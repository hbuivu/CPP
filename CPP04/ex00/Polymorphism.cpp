#include "Polymorphism.hpp"

Animal::Animal()
	:	_type("animal")
{
}

Animal::~Animal()
{
}

void	Animal::makeSound() const
{
	std::cout << "neigh\n";
}

std::string	Animal::getType() const
{
	return (_type);
}

Dog::Dog()
	:	Animal()
{
	_type = "Dog"; //reset the _type to Dog
}

// void	Dog::makeSound() const;
// {
// 	std::cout << "woof\n";
// }

Cat::Cat()
	:	Animal()
{
	_type = "Cat";
}

// void	Cat::makeSound() const;
// {
// 	std::cout << "meow\n";
// }