#include "Polymorphism.hpp"

Cat::Cat()
	:	Animal()
{
	_type = "Cat";
}

void	Cat::makeSound() const
{
	std::cout << "meow\n";
}