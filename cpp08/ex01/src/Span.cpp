#include "Span.hpp"

Span::Span() : _N(0)
{

}

Span::Span(unsigned int N) : _N(N)
{
    _numbers.reserve(_N);
}

Span::Span(const Span &span)
{
    _numbers = span._numbers;
}

void Span::addNumber(int number)
{
    if (_numbers.size() <= _numbers.capacity())
		_numbers.push_back(number);
	else
		throw CustomException::NoPlaceLeft();
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
		throw CustomException::NotEnoughElement();
    std::vector<int> sortedVec = _numbers;
    std::sort(sortedVec.begin(), sortedVec.end());
    int shortest = INT_MAX;
    for (unsigned int i = 1; i < sortedVec.size(); i++) {
        int diff = sortedVec[i] - sortedVec[i - 1];
        if (diff < shortest) 
            shortest = diff;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
		throw CustomException::NotEnoughElement();
    std::vector<int>::iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::iterator max = std::max_element(_numbers.begin(), _numbers.end());
    return (*max - *min);
}

Span &Span::operator=(const Span &span)
{
    if (this == &span)
		return (*this);
	_numbers = span._numbers;
	return (*this);
}

Span::~Span()
{
}
