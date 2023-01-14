#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include "CustomException.hpp"

class CustomException;

class Span
{
    private:
    	std::vector<int> _numbers;
    	unsigned int _N;
    public:
    	Span();
    	Span(unsigned int N);
    	Span(const Span &span);
    	void addNumber(int number);
    	int shortestSpan();
    	int longestSpan();
    	Span &operator=(const Span &span);
    	~Span();
};