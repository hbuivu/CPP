/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:27 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:27 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void	attack() const;
};

#endif

/* NOTES:
we are including a ref to weapon in constructor, because the object must have been precreated
Otherwise, HumanA constructor tries to call default constructor of weapon which does not exist
ALSO, ORDER OF INITIALIZATION IN CONSTRUCTORS MATTER
if _name comes first, it also must be initialized first in constructor
*/