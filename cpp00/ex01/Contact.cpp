#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getName(void)
{
        return (this->name);
}
std::string Contact::getSurName(void)
{
        return (this->surName);
}
std::string Contact::getNickName(void)
{
        return (this->nickName);
}
std::string Contact::getPhone(void)
{
        return (this->phone);
}
std::string Contact::getDarketSecret(void)
{
        return (this->darketSecret);
}
void Contact::setName(std::string name)
{
        this->name = name;
}
void Contact::setSurName(std::string surName)
{
        this->surName = surName;
}
void Contact::setNickName(std::string nickName)
{
        this->nickName = nickName;
}
void Contact::setPhone(std::string phone)
{
        this->phone = phone;
}
void Contact::setDarketSecret(std::string darketSecret)
{
        this->darketSecret = darketSecret;
}

int Contact::read(void)
{
        GetLine getLine;
        std::string text;

        getLine = getLine.Run("Name", text);
        if (getLine.getError() != -1)
                this->setName(getLine.getText());
        else
                return (-1);
        text.clear();
        std::cout.clear();
        getLine = getLine.Run("SurName", text);
        if (getLine.getError() != -1)
                this->setSurName(getLine.getText());
        else
                return (-1);
        text.clear();
        std::cout.clear();
        getLine = getLine.Run("NickName", text);
        if (getLine.getError() != -1)
                this->setNickName(getLine.getText());
        else
                return (-1);
        text.clear();
        std::cout.clear();
        getLine = getLine.Run("Phone", text);
        if (getLine.getError() != -1)
                this->setPhone(getLine.getText());
        else
                return (-1);
        text.clear();
        std::cout.clear();
        getLine = getLine.Run("DarketSecret", text);
        if (getLine.getError() != -1)
                this->setDarketSecret(getLine.getText());
        else
                return (-1);
        text.clear();
        std::cout.clear();
        return (0);
}