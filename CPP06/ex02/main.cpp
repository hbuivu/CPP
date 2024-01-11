/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:19:04 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/10 16:59:54 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *b = generate();
	
	identify(b);
	identify(*b);
	
	delete b;
}

/* 
NOTES:
dynamic_cast operator
-safely converts from a pointer (or reference) to a base type to a pointer (or reference) to a derived type.
-it answers whether we can SAFELY ASSIGN the address of a pointer to a particular type
-invovles run time type check
if the object bound to the pointer is not an object of target type, it fails and value is 0 (for pointers)
in the case of reference, it will throw an exception(bad cast);
requires base class to have at least one virtual function

*/