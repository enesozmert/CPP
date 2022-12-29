#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl
{
    private:

    public:
        Harl();
        ~Harl();
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void complain( std::string level );
};

#endif