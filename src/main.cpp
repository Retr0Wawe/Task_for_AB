#include "Core/includes/XMLTree.hpp"

#include <iostream>

int main()
{
	char ch;
	auto xml = &XMLtree::GetInstance();

	if (!xml->Initialize("tst_2.xml", { "surname", "name", "middleName", "function", "salary" })) {
		std::cout << "File not found!" << std::endl;
		std::exit(0);
	}

	xml->AddElement('e');

	//xml->PrintTree();
}