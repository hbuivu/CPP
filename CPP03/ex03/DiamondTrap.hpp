/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:16:44 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 00:16:44 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string	_name;
	using FragTrap::_hitPts;
	using ScavTrap::_energyPts;
	using FragTrap::_attackDmg;
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(std::string* name);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& src);
	
	void	whoAmI();
	using	ScavTrap::attack;
};

#endif

/* NOTES:
Other solutions
1. keep only one variable between all four classes (_hp, _ep, _ad)
	-Since only one variable exists (inherited from ClapTrap), it automatically takes on the build of the last parent class, in this case ScavTrap
	-manually set the numbers again using same method as from exercise 02 and 01
2. set separate variables in just FragTrap - less work but maybe not as clear
3. Instead of using ScavTrap::attack, make attack function virtual so DiamondTrap uses the latest build of attack
4. instead of using FragTrap::_hitPts, etc. set the variables in DiamondTrap constructor using namespaces of relevant classes
*/
