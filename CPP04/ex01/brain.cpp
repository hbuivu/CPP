#include "Polymorphism.hpp"

Brain::Brain()
	:	_ideas(new std::string[100])
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src) //CHECK THIS
	:	_ideas(new std::string[sizeof(src._ideas)])
{
	std::copy(src._ideas, src._ideas + sizeof(src._ideas), this->_ideas);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src)
{
	if (this != &src && src._ideas && this->_ideas)
		std::copy(src._ideas, src._ideas + 100, this->_ideas);
}