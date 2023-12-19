#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

class WrongCat
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat (const WrongCat& cpy);
	WrongCat& operator=(const WrongCat& og);

	virtual void	makeSound() const;
}
#endif