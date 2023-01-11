#include "Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(const char *s) : number(static_cast<std::string>(s))
{
}

Convert::Convert(const Convert &convert)
{
    *this = convert;
}

Convert::~Convert()
{
}

Convert &Convert::operator=(const Convert &convert)
{
    number = convert.number;
    return *this;
}

Convert::operator int() const
{
    double n = static_cast<double>(*this);
    if (isnan(n) ||
        !(std::numeric_limits<int>::min() <= n && n <= std::numeric_limits<int>::max()))
        throw ImpossibleException();
    return static_cast<int>(n);
}

Convert::operator char() const
{
    int n = static_cast<int>(*this);
    if (!(std::numeric_limits<char>::min() <= n && n <= std::numeric_limits<char>::max()))
        throw ImpossibleException();
    if (!(32 <= n && n <= 126))
        throw NonDisplayableException();
    return static_cast<char>(n);
}

Convert::operator float() const
{
    double n = static_cast<double>(*this);
    return static_cast<float>(n);
}

Convert::operator double() const
{
    char *end;
    double n = std::strtod(number.c_str(), &end);
    if (number.c_str() == end)
        throw ImpossibleException();
    return n;
}

const char *Convert::ImpossibleException::what() const throw()
{
    return "imposible";
}

const char *Convert::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}

std::ostream &operator<<(std::ostream &ostream, const Convert &convert)
{
    try
    {
        char c = static_cast<char>(convert);
        ostream << "char : '" << c << "'\n";
    }
    catch (const std::exception &e)
    {
        ostream << "char : " << e.what() << '\n';
    }

    try
    {
        int i = static_cast<int>(convert);
        ostream << "int : " << i << "\n";
    }
    catch (const std::exception &e)
    {
        ostream << "int : " << e.what() << '\n';
    }

    ostream << std::setprecision(1) << std::fixed;
    try
    {
        float f = static_cast<float>(convert);
        ostream << "float : " << f << "f\n";
    }
    catch (const std::exception &e)
    {
        ostream << "float : " << e.what() << "\n";
    }

    try
    {
        double d = static_cast<double>(convert);
        ostream << "double : " << d << "\n";
    }
    catch (const std::exception &e)
    {
        ostream << "double : " << e.what() << "\n";
    }
    return (ostream);
}