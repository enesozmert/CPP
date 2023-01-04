#include "Brain.hpp"

Brain::Brain()
{
    int i;
    RandomString *rndStr;

    i = -1;
    while (++i < 100)
    {
        rndStr = new RandomString(5);
        _ideas[i] = rndStr->getText();
        delete rndStr;
    }
}

Brain::Brain(const Brain &brain)
{
    int i;
    RandomString *rndStr;

    i = -1;
    while (++i < 100)
    {
        rndStr = new RandomString(5);
        _ideas[i] = rndStr->getText();
        delete rndStr;
    }
    *this = brain;
}

void Brain::printFirstIdeas(void) const
{
    std::cout << BLUE << "[Ideas] " << END << _ideas[0] << "," << _ideas[1] << "," << _ideas[2] << "," << _ideas[3] << "," << _ideas[4] << ",... ";
}

Brain &Brain::operator=(const Brain &brain)
{
    int i;

    i = -1;
    if (this == &brain)
        return (*this);
    while (++i < 100)
        this->_ideas[i] = brain._ideas[i];
    return (*this);
}

Brain::~Brain()
{
}