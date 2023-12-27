/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:48:35 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 10:57:24 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat (const WrongCat& cpy);
	~WrongCat();
	WrongCat& operator=(const WrongCat& og);

	void	makeSound() const;
};

#endif

/* NOTES:
for a class to be polymorphic, it must employ at least one virtual function 
*/