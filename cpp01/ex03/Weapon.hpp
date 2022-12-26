#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon( std::string type);
        ~Weapon();
        std::string const	getType( void );
        void setType(std::string type);
};

#endif