/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:26:52 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 21:26:52 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPts;
	unsigned int	_energyPts;
	unsigned int	_attackDmg;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(std::string* name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& src);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif

/* NOTES:
std::string CANNOT be NULL. it is not a pointer. an empty string is denoted as ""
adding ClapTrap(std::string* name) just in case someone tests NULL.
But if they test NULL, it means they dont fundamentally understand what std::string is. It is a class not a pointer
A literal CANNOT be a ref! Except string values which count as an lvalue

Lvalue is a reference
Rvalue is a value
*/