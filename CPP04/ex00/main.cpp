#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); 
	// j->makeSound();
	// meta->makeSound();

	// const Cat* catPtr = dynamic_cast<const Cat*>(i);
	// if (catPtr)
    // 	catPtr->makeSound();	

	// delete meta;
	// delete j;
	// delete i;

	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	const WrongCat* catPtr = dynamic_cast<const WrongCat*>(i);
	if (catPtr)
    	catPtr->makeSound();	

	delete meta;
	delete j;
	delete i;
}