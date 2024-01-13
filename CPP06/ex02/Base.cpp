/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:27:10 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/13 11:01:09 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){};
A::~A(){};
B::~B(){};
C::~C(){};

Base*	generate(void)
{
	
	srand(static_cast<unsigned>(time(NULL)));
    int pick = rand() % 3;
	Base *newClass = NULL;
	switch (pick)
	{
		case 0: newClass = new A(); break;
		case 1: newClass = new B(); break;
		case 2:	newClass = new C(); break;
		default: newClass = NULL; break;
	}
	return (newClass);
}

void	identify(Base* p)
{
	if (p == NULL)
		return ;
	if (A* isItA = dynamic_cast<A*>(p))//if it not true, isItA == NULL (or 0)
		isItA->printType();
	else if (B* isItB = dynamic_cast<B*>(p))
		isItB->printType();
	else if (C* isItC = dynamic_cast<C*>(p))
		isItC->printType();
	else
		std::cout << "UNKNOWN\n";
}

void	identify(Base& p)
{
	try
	{
		A& isItA = dynamic_cast<A&>(p); //if not true, an exception is thrown
		isItA.printType();
	}
	catch(const std::exception& e)
	{
		try
		{
			B& isItB = dynamic_cast<B&>(p);
			isItB.printType();
		}
		catch(const std::exception& e)
		{
			try
			{
				C& isItC = dynamic_cast<C&>(p);
				isItC.printType();
			}
			catch(const std::exception& e)
			{
				std::cout << "UNKNOWN\n";
			}
		}
	}
}

/* NOTES:
try {
    dynamic_cast<A&>(p).printType();
} catch (const std::exception& e) {
    try {
        dynamic_cast<B&>(p).printType();
    } catch (const std::exception& e) {
        try {
            dynamic_cast<C&>(p).printType();
        } catch (const std::exception& e) {
            std::cout << "UNKNOWN\n";
        }
    }
}
Shorter format
*/