/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:16:32 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/10 15:41:39 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>

class Base
{
public:
	virtual ~Base();
};

class A : public Base
{
public:
		
};

class B : public Base
{
};

class C : public Base
{
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

/* NOTES:
an empty class does not contain any variable members. However, it does have functions
empty classes are usually 1 byte in size - so that 2 diff objs can take up two diff spaces in memory
this byte does not need to be separate. so if base class is empty and there is an int in class A, the size would be 4

Class A : public Base -> size 1
Class A : virtual public Base -> size 8
	a pointer to a virtual base class table is included to keep track of shared instance 

*/