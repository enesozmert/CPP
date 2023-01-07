#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <cstring>

class ALiteral
{
    private:
        virtual void checkOutOfRange() = 0;
        virtual bool checkType() = 0;
    protected:
        const char *_value;
    public:
        bool _isType;
        bool _isOutOfRange;
        bool _isLimit;
        bool _isConvert;
        ALiteral();
        ALiteral(const char *value);
        ALiteral(const ALiteral &literal);
        virtual void convert() = 0;
        ALiteral &operator=(const ALiteral &literal);
        virtual ~ALiteral();
};

