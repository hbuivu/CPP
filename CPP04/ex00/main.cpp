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
	std::cout << "j is: " << j->getType() << std::endl;
	std::cout << "i is: " << i->getType() << std::endl;
	std::cout << "i makes sound: ";
	i->makeSound(); 
	std::cout << "j makes sound: ";
	j->makeSound();
	std::cout << "meta makes sound: ";
	meta->makeSound();

	const WrongCat* catPtr = dynamic_cast<const WrongCat*>(i);
	if (catPtr)
	{
		std::cout << "catptr makes sound: ";
    	catPtr->makeSound();	
	}

	delete meta;
	delete j;
	delete i;

	// WrongCat c;
	// c.makeSound();

	// const WrongAnimal *wc = new WrongCat();
	// wc->makeSound();
}