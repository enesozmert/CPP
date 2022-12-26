#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "ProString.hpp"

class PhoneBook
{
private:
    int        contactCount;
    Contact    contactList[8];
    ProString  proString;
public:
    PhoneBook();
    ~PhoneBook();
    void setContactList(Contact contact, int index);
    Contact getContactList(int index);
    void print(void);
    int getContactCount(void);
};
#endif