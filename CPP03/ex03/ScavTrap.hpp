/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:31:41 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 21:31:41 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap:	virtual public ClapTrap
{
protected:
	unsigned int	_hitPts;
	unsigned int	_energyPts;
	unsigned int	_attackDmg;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();
	
	ScavTrap&	operator=(const ScavTrap& src);

	virtual void	attack(const std::string& target);
	void	guardGate();
};

#endif