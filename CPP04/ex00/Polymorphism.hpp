#ifndef POLYMORPHISM_H
# define POLYMORPHISM_H

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	~Animal();
	Animal(const Animal& cpy);

	Animal&	operator=(const Animal& og);
	
	std::string	getType() const;
	void		makeSound() const;
};

class Dog:	public Animal
{
public:
	Dog();
	~Dog();
	Dog (const Dog& cpy);
	Dog& operator=(const Dog& og);
};

class Cat:	public Animal
{
public:
	Cat();
	~Cat();
	Cat (const Cat& cpy);
	Cat& operator=(const Cat& og);
};

#endif
