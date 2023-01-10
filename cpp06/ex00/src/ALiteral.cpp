#include "ALiteral.hpp"

ALiteral::ALiteral(): _value(""), _isType(false),_isStringError(false), _isOutOfRange(false),  _isConvert(false), _limit(""), _isLimit(false)
{
}

ALiteral::ALiteral(const char *value) :_value(value), _isType(false) , _isStringError(false), _isOutOfRange(false), _isConvert(false), _limit(""), _isLimit(false)
{

}

ALiteral::ALiteral(const ALiteral &literal) : _isType(literal._isType) ,_isStringError(literal._isStringError), _isOutOfRange(literal._isOutOfRange), _isConvert(literal._isConvert),  _limit(literal._limit), _isLimit(literal._isLimit)
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