#include "../includes/XMLTree.hpp"

#include <iostream>

XMLtree::XMLtree()
{
	#if defined(_WIN32) || defined(_WIN64)
		system("chcp 65001 && cls"); 
	#endif
}

std::string XMLtree::GetStrFromChild(const XMLElement* _elem, const char* _child_name) const
{
	auto str = _elem->FirstChildElement(_child_name)->GetText();

	return str == NULL ? "element " + std::string(_child_name) + " not found!" : str;
}

bool XMLtree::Initialize(const char* _file_path)
{
	return doc.LoadFile(_file_path) != XML_SUCCESS ? false : true;
}

void XMLtree::AddElement(const char* _name) noexcept
{
	auto pTop = doc.RootElement();
	auto pElement = pTop->FirstChildElement("department");

	auto pRoot = doc.NewElement("Test");
	pElement->InsertEndChild(pRoot);

	//finish it, becose doesnt work
}

void XMLtree::ChangeElement() noexcept
{

}

void XMLtree::DeleteElement() noexcept
{

}

void XMLtree::PrintTree() const noexcept
{
	auto pRootElement = doc.RootElement();

	if (pRootElement != nullptr) {
		auto pDepartaments = pRootElement->FirstChildElement("department");
		while (pDepartaments) {
			std::cout << "Department: " << pDepartaments->Attribute("name") << std::endl;
			auto pEmployments = pDepartaments->FirstChildElement("employments");
			if (pEmployments != nullptr) {
				auto pEmployment = pEmployments->FirstChildElement("employment");
				if (pEmployment != nullptr) {
					std::cout << "  \t" << " Surname: " << GetStrFromChild(pEmployment, "surname") << std::endl;
					std::cout << "  \t" << " Name: " << GetStrFromChild(pEmployment, "name") << std::endl;
					std::cout << "  \t" << " MiddleName: " << GetStrFromChild(pEmployment, "middleName") << std::endl;
					std::cout << "  \t" << " Function: " << GetStrFromChild(pEmployment, "function") << std::endl;
					std::cout << "  \t" << " Salary: " << GetStrFromChild(pEmployment, "salary") << std::endl;
				} else {
					std::cout << "Employment not recognized!" << std::endl;
				}
				std::cout << std::endl;
			} else {
				std::cout << "Employments not recognized!" << std::endl;
			}
			pDepartaments = pDepartaments->NextSiblingElement("department");
		}
	} else {
		std::cout << "File not recognized!" << std::endl;
	}
}