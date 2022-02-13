#include "../includes/XMLTree.hpp"

#include <iostream>

XMLtree::XMLtree() : file_path(nullptr)
{
#if defined(_WIN32) || defined(_WIN64)
	system("chcp 65001 && cls");
#endif
}

XMLtree::~XMLtree()
{
	doc.SaveFile(file_path);
}

std::string XMLtree::GetStrFromChild(const XMLElement* _elem, const char* _child_name) const
{
	auto str = _elem->FirstChildElement(_child_name)->GetText();

	return str == NULL ? "element " + std::string(_child_name) + " not found!" : str;
}

bool XMLtree::Initialize(const char* _file_path, std::vector<std::string> _basic_names)
{
	this->file_path = _file_path;
	this->elem_names = std::move(_basic_names);
	return doc.LoadFile(_file_path) != XML_SUCCESS ? false : true;
}

void XMLtree::AddElement(const char ch) noexcept
{
	auto pTop = doc.RootElement();
	std::string str;

	if (ch == 'd') {
		std::cout << "Enter department name: ";
		std::getline(std::cin, str);

		XMLElement* pDepartment = doc.NewElement("department");
		pDepartment->SetAttribute("name", str.c_str());
		pTop->InsertEndChild(pDepartment);

		XMLNode* pEmployments = doc.NewElement("employments");
		pDepartment->InsertEndChild(pEmployments);

		XMLNode* pEmployment = doc.NewElement("employment");
		pEmployments->InsertEndChild(pEmployment);

		for (const auto& names : elem_names) {
			XMLElement* pFirstElem = doc.NewElement(names.c_str());
			str.clear();

			std::cout << "Enter data for " << names << ": ";
			std::getline(std::cin, str);

			pFirstElem->SetText(str.c_str());
			pEmployment->InsertEndChild(pFirstElem);
		}
	}
	else if (ch == 'e') {
		XMLElement* pElem = pTop->FirstChildElement("department");
		std::cout << "Enter department name: ";
		std::getline(std::cin, str);

		while (pElem) {
			auto str_atr = pElem->Attribute("name");

			if (str == str_atr) {
				std::cout << pElem->Attribute("name");
				break;
			}
			pElem = pElem->NextSiblingElement();
		}
	}

	doc.SaveFile(file_path);
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
				while (pEmployment) {
					for (const auto& elems : elem_names) {
						std::cout << "  \t" << elems << ": " << GetStrFromChild(pEmployment, elems.c_str()) << std::endl;
					}
					pEmployment = pEmployment->NextSiblingElement("employment");
					std::cout << std::endl;
				}
			}
			else {
				std::cout << "Employments not recognized!" << std::endl;
			}
			pDepartaments = pDepartaments->NextSiblingElement("department");
		}
	}
	else {
		std::cout << "File not recognized!" << std::endl;
	}
}
