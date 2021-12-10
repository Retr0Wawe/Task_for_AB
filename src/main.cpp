#include "Core/includes/XMLTree.hpp"
#include <iostream>

using namespace tinyxml2;

int main()
{
    XMLDocument doc;
    
    
    doc.LoadFile("Text.xml");


    system("pause");
}