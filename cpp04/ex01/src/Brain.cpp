#include "Brain.hpp"

Brain::Brain()
{
    int i;
    RandomString rndStr(5);

    i = -1;
    while (++i < 100)
        _ideas[i] = rndStr.getText();
}

Brain::Brain(const Brain &brain)
{
    int i;
    RandomString rndStr(5);

    i = -1;
    while (++i < 100)
        _ideas[i] = rndStr.getText();
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