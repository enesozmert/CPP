#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include "GetLine.hpp"

class Contact
{
    private:
        std::string name;
        std::string surName;
        std::string nickName;
        std::string phone;
        std::string darketSecret;
    public:
        Contact();
        ~Contact();
        std::string getName(void);
        std::string getSurName(void);
        std::string getNickName(void);
        std::string getPhone(void);
        std::string getDarketSecret(void);
        void setName(std::string name);
        void setSurName(std::string surName);
        void setNickName(std::string nickName);
        void setPhone(std::string phone);
        void setDarketSecret(std::string darketSecret);
        int read(void);
};

#endif