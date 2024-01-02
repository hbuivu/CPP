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
	Animal **zoo = new Animal*[100];
	
	for (int i = 0; i < 50; i++)
		zoo[i] = new Cat();
	for (int i = 50; i < 100; i++)
		zoo[i] = new Dog();
	for (int i = 0; i < 100; i++)
		delete zoo[i];
	delete[] zoo;

	// Dog d;
	// Dog b(d);
	// Dog a;
	// Dog c = a;

}

/* NOTES:
Code 1 issues:
Animal *zoo = new Animal[2];
for (int i = 0; i < 2; i++)
	zoo[i] = Cat();

Here, zoo[i] only copies over the animal portion of Cat class 
When we assign a Derived object to a Base object, only the Base portion of the Derived object is copied. 

Code 2 issues:
Animal *zoo = new Animal[2];
for (int i = 0; i < 2; i++)
	new (&zoo[i]) Cat();

If we dynamically allocate with placement new, we run into issues with space
Cat contains an additional pointer Brain *_brain; However here we only allocate enough space for an animal class
Therefore, there will be some memory corruption, when trying to squeeze a cat class into an animal array

Use dynamic casting to convert base class pointers into derived class pointers
*/