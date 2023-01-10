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
    protected:
        virtual void print(std::ostream &o) const = 0;
        const char *_value;
        int _intValue;
        float _floatValue;
        double _doubleValue;
        char _charValue;
    public:
        bool _isType;
        bool _isOutOfRange;
        bool _isLimit;
        bool _isConvert;
        ALiteral();
        ALiteral(const char *value);
        ALiteral(const ALiteral &literal);
        virtual void convert() = 0;
        virtual bool checkType() = 0;
        ALiteral &operator=(const ALiteral &literal);
        virtual ~ALiteral();
};

