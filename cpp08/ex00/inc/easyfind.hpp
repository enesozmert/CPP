#pragma once

#include <algorithm>
#include "CustomException.hpp"

class CustomException;

template <typename T>
typename T::iterator easyfind(T &t, int n)
{
    typename T::iterator it;
    it = std::find(t.begin(), t.end(), n);
    if (it == t.end())
        throw CustomException::NotFound();
    return (it);
}