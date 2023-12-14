/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:13 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:13 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
private:
	std::string	_type;
	Weapon();
public:
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType();
	void				setType(std::string newType);
};

#endif

/* NOTES: 
Always include semicolon after class!!!!
look up when const comes before and after a type
& comes at the end of type if its a ref*/