/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:58:37 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 14:58:37 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif