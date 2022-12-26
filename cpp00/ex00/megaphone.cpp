#include <iostream>
#include <string>

char *stringToUpper(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (isalnum(str[i]))
            str[i] = toupper(str[i]);
    }
    return (str);
}

void noneArg(int count)
{
    if (count == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void defaultArg(int count, char **arg)
{
    int i;

    i = 0;
    if (count <= 1)
        return;
    while (++i < count)
    {
        std::cout << stringToUpper(arg[i]) << std::ends;
        if (i != count - 1)
            std::cout << " ";
    }
}

int main(int count, char **arg)
{
    noneArg(count);
    defaultArg(count, arg);
}