#include <iostream>
#include <pthread.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <semaphore.h>

#define num_of_threads 2
#define write_file_delay 2000
#define read_file_delay 10000

using namespace std;

struct param
{
    string str;
};

pthread_mutex_t sem_mutex; // семафор блокировки потоков записи
sem_t sem_count; // семафор ,счетчик записанных данных
pthread_cond_t stop_read_thread; // семафор блокиратор потоков чтения

// потоковая функция записи в фаил
void *write_file(void *arg)
{
    param *par = (param*)arg;

    ofstream write_file("output.txt"); // получаем дескриптор фаил для записи

    if (write_file.is_open())
    {
        while (true)
        {
            pthread_mutex_lock(&sem_mutex); // блокируем один из потоков записи

            for (int i = 0; i < 100; i++)
            {
                write_file << par->str << "\t Thread count: " << i << endl;
                sem_post(&sem_count); // сообщаем что в файле появились данные
            }

            pthread_cond_signal(&stop_read_thread); // посылаем сигнал разблокировки потока чтения
            pthread_mutex_unlock(&sem_mutex);     // разблокируем один из потоков записи
            usleep(write_file_delay);                           // ожидаем , даем потоку считать данные
        }
    } else {
        cout << "Unable to open file for write" << endl;
    }

    return nullptr;
}

// потоковая функция чтения файла
void *read_file(void *arg)
{
    ifstream read_file("output.txt"); // получаем дескриптор файла для чтения

    if (read_file.is_open())
    {
        string tmp_str;
        pthread_mutex_lock(&sem_mutex);
        pthread_cond_wait(&stop_read_thread, &sem_mutex); // ожидаем если выполняется поток записи

        while(!read_file.eof())
        {
            sem_wait(&sem_count); // ожидаем поступления данных в фаил
            getline(read_file, tmp_str); // получаем строку из файла

            cout << tmp_str << endl;
            usleep(read_file_delay);
        }
        pthread_mutex_unlock(&sem_mutex);
    } else {
        cout << "Unable to open file for read" << endl;
    }

    return nullptr;
}

int main()
{
    sem_init(&sem_count, 0, 0); //count init

    pthread_t writers[num_of_threads];
    pthread_t readers[num_of_threads];
    param args;

    for(int i = 0; i < num_of_threads; i++){
        args.str = "Write thread count: " + std::to_string(i);
        pthread_create(&writers[i], 0, write_file, &args);
    }

    for(int i = 0; i < num_of_threads; i++){
        pthread_create(&readers[i], 0, read_file, 0);
    }

    for(int i = 0; i < num_of_threads; i++){
        pthread_join(readers[i], 0);
    }

    for(int i = 0; i < num_of_threads; i++){
        pthread_join(writers[i], 0);
    }
}
