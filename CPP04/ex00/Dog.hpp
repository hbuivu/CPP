/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:55 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/02 13:20:18 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog :	public Animal
{
public:
	Dog();
	Dog(const Dog& src);
	virtual ~Dog();
	Dog& operator=(const Dog& src);

	virtual void	makeSound() const;
};

#endif