#include "ALiteral.hpp"

ALiteral::ALiteral(): _value(""), _isType(false), _isOutOfRange(false), _isLimit(false), _isConvert(false)
{
}

ALiteral::ALiteral(const char *value) :_value(value), _isType(false) , _isOutOfRange(false), _isLimit(false), _isConvert(false)
{

}

ALiteral::ALiteral(const ALiteral &literal) : _isType(literal._isType) , _isOutOfRange(literal._isOutOfRange), _isLimit(literal._isLimit), _isConvert(literal._isConvert)
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