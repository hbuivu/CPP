/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:59 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 10:47:59 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* animal = new Animal();
	// const Animal* d = new Dog();
	// const Animal* c = new Cat();
	// std::cout << d->getType() << " " << std::endl;
	// std::cout << c->getType() << " " << std::endl;
	// d->makeSound(); 
	// c->makeSound();
	// animal->makeSound();

	// const Cat* catPtr = dynamic_cast<const Cat*>(c);
	// if (catPtr)
    // 	catPtr->makeSound();	

	// delete animal;
	// delete d;
	// delete c;

	const WrongAnimal* animal = new WrongAnimal();
	const Animal* d = new Dog();
	const WrongAnimal* wc = new WrongCat();
	std::cout << "d is: " << d->getType() << std::endl;
	std::cout << "wc is: " << wc->getType() << std::endl;
	std::cout << "d makes sound: ";
	d->makeSound(); 
	std::cout << "wc makes sound: ";
	wc->makeSound();
	std::cout << "animal makes sound: ";
	animal->makeSound();

	const WrongCat* catPtr = dynamic_cast<const WrongCat*>(wc);
	if (catPtr)
	{
		std::cout << "catptr makes sound: ";
    	catPtr->makeSound();	
	}

	delete animal;
	delete d;
	delete wc;
}

/*
NOTES:
dynamic casting is used for safe "downcasting" - casting a parent pointer to a child pointer
"upcasting" is always allowed and is when we cast a child pointer to a parent pointer
*/