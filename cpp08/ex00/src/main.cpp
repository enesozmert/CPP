#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> _vec(5);
    std::array<int, 5> _arr = {0, 1, 2, 3, 4};
    std::list<int> _list;

    _list.push_back(5);
    _list.push_back(6);
    _list.push_back(7);

    _vec.push_back(3);
    _vec.push_back(4);
    _vec.push_back(5);
    try
    {
        std::cout << *easyfind(_vec, 10) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << *easyfind(_arr, 3) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << *easyfind(_vec, 4) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << *easyfind(_list, 7) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}