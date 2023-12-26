#ifndef WRONGGANIMAL_HPP
# define WRONGGANIMAL_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat (const WrongCat& cpy);
	WrongCat& operator=(const WrongCat& og);

	void	makeSound() const;
}

#endif