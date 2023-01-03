#include <string>
#include <iostream>
#include <iomanip>
#include "RandomString.hpp"

RandomString::RandomString()
{
    this->text = this->run(5);
}

RandomString::RandomString(int size)
{
    this->text = this->run(size);
}

std::string RandomString::getText()
{
    return (this->text);
}

std::string RandomString::run(int size)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    const std::string alphaNum = "abcdefghijklmnopqrstuvwxyz";
    std::string randomStr = "";

    for (int i = 0; i < size; i++)
        randomStr += alphaNum[(std::rand() * ltm->tm_sec % alphaNum.size()) % alphaNum.size()];
    return (randomStr);
}

RandomString::~RandomString()
{
}