#ifndef POLYMORPHISM_H
# define POLYMORPHISM_H

# include <iostream>
# include <string>

class Brain //mixin class
{
protected:
	std::string*	_ideas;
public:
	Brain();
	Brain(const Brain& src);
	~Brain();
	Brain&	operator=(const Brain& src);
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

class Dog:	public Animal, public Brain
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

class Cat:	public Animal, public Brain
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
