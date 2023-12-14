/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:59 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:59 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;
	HumanB();
public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon& weapon);
	void	attack() const;
};

#endif