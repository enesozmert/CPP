#include "ALiteral.hpp"

ALiteral::ALiteral(): _value(""), _isType(false), _isOutOfRange(false), _isLimit(false), _isConvert(false)
{
}

ALiteral::ALiteral(const char *value) :_value(value), _isType(false) , _isOutOfRange(false), _isLimit(false), _isConvert(false)
{

}

ALiteral::ALiteral(const ALiteral &literal)
{
    *this = literal;
}

ALiteral &ALiteral::operator=(const ALiteral &literal)
{
    if (this == &literal)
        return (*this);
    return (*this);
}

ALiteral::~ALiteral()
{
    
}