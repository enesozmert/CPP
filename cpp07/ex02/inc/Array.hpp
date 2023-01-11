#pragma once

# include <iostream>
# include "CustomException.hpp"

class CustomException;

template<typename T>
class Array
{
    private:
        T *_array;
        unsigned int _n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &array);
        Array	&operator=(const Array &obj);
        T		&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;
        unsigned int size() const;
        ~Array();
};

template <typename T>
Array<T>::Array()
{
    _n = 0;
    _array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _n = n;
	_array = new T[n];
	for (unsigned int i = 0; i < _n; i++)
	{
		_array[i] = 0;
	}
}

template <typename T>
Array<T>::Array(const Array &array)
{
    _n = array.size();
	_array = new T[array.size()];
	for (unsigned int i = 0; i < _n; i++)
	{
		_array[i] = array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array)
{
    if (this == &array)
        return (*this);
    delete[] _array;
    _array = new T[array.size()];
    _n = array.size();
    for (unsigned int i = 0; i < _n; i++)
        _array[i] = array[i];
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw CustomException::OutofBounds();
    return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _n)
        throw CustomException::OutofBounds();
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_n);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}
