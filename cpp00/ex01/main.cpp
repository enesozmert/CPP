#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "ProString.hpp"
#include <iostream>
#include <string>

int main()
{
    int index;
    int result;
    Contact contact;
    PhoneBook phoneBook;
    ProString proString;
    std::string selecetCrud;

    index = 0;
    result = 0;
    while (true)
    {
        std::cout << std::endl
                  << "Choose and write >> [ ADD | SEARCH | EXIT ] : " << std::endl;
        if (!(std::getline(std::cin, selecetCrud)))
            exit(1);
        if (std::cin.eof())
            exit(1);
        selecetCrud = proString.toLower(selecetCrud);
        if (!selecetCrud.compare("add"))
        {
            result = contact.read();
            if (result != -1)
            {
                phoneBook.setContactList(contact, index);
                index = phoneBook.getContactCount();
            }
        }
        else if (!selecetCrud.compare("search"))
        {
            phoneBook.print();
        }
        else if (!selecetCrud.compare("exit"))
        {
            std::cout << "Next Goodbye!" << std::endl;
            break ;
        }
        else
            std::cout << "This command dosen't exist." << std::endl;
    }
    return (0);
}
