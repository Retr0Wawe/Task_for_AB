#include "Core/includes/XMLTree.hpp"

#include <iostream>

int main()
{
    char ch;
    auto xml = &XMLtree::GetInstance();

    if (!xml->Initialize("tst_2.xml")) {
        std::cout << "File not found!" << std::endl;
        std::exit(0);
    }

    //xml->AddElement('d');

    do {
        std::cout << "Select an action: " << std::endl << std::endl;
        std::cout << "P - display content." << std::endl
            << "A - add element" << std::endl
            << "D - delete element" << std::endl
            << "E - exit program" << std::endl << std::endl;

        std::cout << ">>";
        std::cin >> ch;

        switch (toupper(ch)) 
        {
        case 'P':
            xml->PrintTree();
            break;
        default:
            std::cout << "Action not recognized!" << std::endl;
        }
    } while (ch != 'E');
}