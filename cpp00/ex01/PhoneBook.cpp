#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setContactList(Contact contact, int index)
{
    if (contact.getName().length() > 0)
        contactList[index % 8].setName(contact.getName());
    if (contact.getSurName().length() > 0)
        contactList[index % 8].setSurName(contact.getSurName());
    if (contact.getNickName().length() > 0)
        contactList[index % 8].setNickName(contact.getNickName());
    if (contact.getPhone().length() > 0)
        contactList[index % 8].setPhone(contact.getPhone());
    if (contact.getDarketSecret().length() > 0)
        contactList[index % 8].setDarketSecret(contact.getDarketSecret());
    this->contactCount++;
}

Contact PhoneBook::getContactList(int index)
{
    Contact result = contactList[index % 8];
    return (result);
}

void PhoneBook::print(void)
{
    int i;

    i = -1;
    std::cout << this->contactCount << std::endl;
    if (this->contactCount > 8)
        this->contactCount = 8;
    while (++i < this->contactCount)
    {
        std::cout <<
        std::setw(10) << proString.cutLettersToTen(contactList[i].getName()) << "|" << 
        std::setw(10) << proString.cutLettersToTen(contactList[i].getSurName()) << "|" << 
        std::setw(10) << proString.cutLettersToTen(contactList[i].getNickName()) << "|" << 
        std::setw(10) << proString.cutLettersToTen(contactList[i].getPhone()) << "|" << 
        std::setw(10) << proString.cutLettersToTen(contactList[i].getDarketSecret()) << "|" << std::endl;
    }
}

int PhoneBook::getContactCount(void)
{
    return (this->contactCount);
}