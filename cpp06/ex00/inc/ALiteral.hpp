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
    protected:
        const char *_value;
        int _intValue;
        float _floatValue;
        double _doubleValue;
        char _charValue;
        virtual void print(std::ostream &o) const = 0;
    public:
        bool _isType;
        bool _isStringError;
        bool _isOutOfRange;
        bool _isConvert;
        std::string	_limit;
        bool        _isLimit;
        ALiteral();
        ALiteral(const char *value);
        ALiteral(const ALiteral &literal);
        virtual void convert() = 0;
        virtual bool checkType() = 0;
        virtual void checkOutOfRange() = 0;
        ALiteral &operator=(const ALiteral &literal);
        virtual ~ALiteral();
};

