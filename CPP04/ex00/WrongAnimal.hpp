#ifndef WRONGGANIMAL_HPP
# define WRONGGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& cpy);
	WrongAnimal&	operator=(const WrongAnimal& og);

	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif