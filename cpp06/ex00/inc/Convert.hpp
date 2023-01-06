#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>

class Convert
{
    private:
        
    public:
        Convert();
        Convert(const Convert &convert);
        Convert &operator=(const Convert &convert);
        ~Convert();
};
std::ostream &operator<<(std::ostream &ostream, const Convert &convert);

