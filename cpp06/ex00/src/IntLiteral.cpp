#include "IntLiteral.hpp"

IntLiteral::IntLiteral()
{

}
IntLiteral::IntLiteral(const IntLiteral &intLiteral)
{
    *this = intLiteral;
}
const int IntLiteral::getNum() const
{
    return (_num);
}
void IntLiteral::setNum(int num)
{
    _num = num;
}
bool IntLiteral::getResult() const
{
    return (result);
}
void IntLiteral::run(ALiteral const &literal)
{

}
IntLiteral &IntLiteral::operator=(const IntLiteral &intLiteral)
{

}

std::ostream &IntLiteral::operator<<(std::ostream &ostream, const IntLiteral &intLiteral)
{

}
IntLiteral::~IntLiteral()
{
    
}