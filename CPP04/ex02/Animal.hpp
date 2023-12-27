/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:26:39 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/26 18:26:39 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal& src);
	virtual	~Animal();
	Animal&	operator=(const Animal& src);
	
	std::string		getType() const;
	virtual void	makeSound() const = 0;
};

#endif

/* NOTES:
A virtual function is a member function that resolves to the most derived version of the function
A virtual inheritance (ChildClass : virtual public ParentClass) ensures only one copy of the grandparent class is included if two parent class inherits the same class
Always make destructors virtual if dealing with inheritance - see notes

Pure virtual functions and abstract base classes
A pure virtual function is meant to be modified by child classes and does not have a body!
	ex: virtual int fun() const = 0;
To create an abstract base class (in which it cannot be instantiated) at least one function should be a pure virtual function
*/
