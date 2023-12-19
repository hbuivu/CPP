#ifndef POLYMORPHISM_H
# define POLYMORPHISM_H

# include <iostream>
# include <string>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& cpy);
	Brain&	operator=(const Brain& og);
};

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	virtual	~Animal();
	Animal(const Animal& cpy);

	Animal&	operator=(const Animal& og);
	
	std::string		getType() const;
	virtual void	makeSound() const;
};

class Dog:	public Animal
{
private:
	Brain	*_brain;
public:
	Dog();
	~Dog();
	Dog (const Dog& cpy);
	Dog& operator=(const Dog& og);

	virtual void	makeSound() const;
};

class Cat:	public Animal
{
private:
	Brain	*_brain;
public:
	Cat();
	~Cat();
	Cat (const Cat& cpy);
	Cat& operator=(const Cat& og);

	virtual void	makeSound() const;
};

#endif
