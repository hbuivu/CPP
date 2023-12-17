#include "Polymorphism.hpp"

Dog::Dog()
	:	Animal()
{
	_type = "Dog"; //reset the _type to Dog
}

void	Dog::makeSound() const
{
	std::cout << "woof\n";
}