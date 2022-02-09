#include "Core/includes/XMLTree.hpp"
#include <iostream>

using namespace tinyxml2;

int main()
{
    XMLDocument doc;

    if (doc.LoadFile("demo.xml") == XML_SUCCESS)
    {
        std::cout << "Load Succesful!" << std::endl;
    }

    XMLElement* pRootElement = doc.RootElement(); //<file> root element

    if (pRootElement != NULL) {
        auto pAccounts = pRootElement->FirstChildElement("Accounts");
        if (pAccounts != NULL) {
            auto pAccount = pAccounts->FirstChildElement("Account");
            while (pAccount) {
                auto pAccountNo = pAccount->FirstChildElement("AccountNo");
                std::cout << "Data: " << pAccountNo->GetText() << std::endl;
                if (pAccountNo != NULL) {
                    auto pAccountType = pAccount->FirstChildElement("type");
                    std::cout << "Data: " << pAccountType->GetText() << std::endl;
                }
                pAccount = pAccount->NextSiblingElement("Account");
            }
        }
    }
}