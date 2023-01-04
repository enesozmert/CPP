#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <ctime>

class RandomString
{
    private:
        std::string text;
        std::string run(int size);
    public:
        RandomString();
        RandomString(int size);
        std::string getText();
        ~RandomString();
};