/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:39:18 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 22:39:18 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap:	public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(std::string* name);
	FragTrap(const FragTrap& src);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& src);

	void	highFivesGuys();
};

#endif