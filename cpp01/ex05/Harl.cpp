#include "Harl.hpp"

typedef void (Harl::*method_function)(void);

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
    << std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
    << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
              << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i;
    std::string levels[4];

    i = -1;
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
    method_function p[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    while (++i < 4)
    {
        if (levels[i].compare(level) == 0)
        {
            (this->*p[i])();
            return ;
        }
    }
    if (i > 3)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}