#include "../includes/XMLTree.hpp"

#include <iostream>

bool XMLtree::Initialize(const char* _file_path) noexcept
{
	if (doc.LoadFile(_file_path) != XML_SUCCESS) {
		return false;
	} return true;
}

void XMLtree::PrintTree() const noexcept
{
	auto pRootElement = doc.RootElement();

	if(pRootElement != nullptr) {
		auto pDepartaments = pRootElement->FirstChildElement("department");
		//std::cout << pDepartaments; название департамента
		if (pDepartaments != nullptr) {
			auto pEmployments = pDepartaments->FirstChildElement("employments");
			if (pEmployments != nullptr) {
				auto pEmployment = pEmployments->FirstChildElement("employment");
				auto str = pEmployment->FirstChildElement("surname")->GetText();
			}
		}
	}
}