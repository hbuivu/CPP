/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:00:13 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/13 10:54:25 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& src){(void) src;}

Serializer::~Serializer(){}

Serializer&	Serializer::operator=(const Serializer& src)
{
	(void) src;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

/* NOTES:
https://stackoverflow.com/questions/34291377/converting-a-non-void-pointer-to-uintptr-t-and-vice-versa
Using reinterpret_cast is generally preferred when dealing with low-level conversions between pointers and integers, 
as it indicates that you are intentionally treating the bits of one type as if they were another type.
The reinterpret_cast operator converts a null pointer value to the null pointer value of the destination type

return (uintptr_t)(void *)(ptr); <- this is also valid
*/
