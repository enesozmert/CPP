#pragma once
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T, std::vector<T> > 
{
	public:
		MutantStack() {};
		MutantStack(MutantStack const & other):std::stack<T, std::vector<T> >(other) {};

		typedef typename std::vector<T>::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

        MutantStack & operator=(MutantStack const & mutantStack) {
			if (mutantStack != *this) {
				this->c = mutantStack.c;
			}
			return *this;   
		};
        ~MutantStack() {
			this->c.clear();
		};
};