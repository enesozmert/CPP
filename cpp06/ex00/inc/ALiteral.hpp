#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class ALiteral
{
    private:
    public:
        bool result;
        ALiteral();
        ALiteral(const ALiteral &literal);
        virtual bool getResult() const = 0;
        virtual void run(ALiteral const &literal) = 0;
        ALiteral &operator=(const ALiteral &literal);
        ~ALiteral();
};

