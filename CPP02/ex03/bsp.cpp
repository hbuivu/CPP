/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:23:53 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 23:23:53 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

struct Point //default is public
{
	Fixed	x;
	Fixed	y;
}

Fixed	dotProduct(Point p1, Point p2, Point p)
{
	return (p2.y - p1.y) * (p.x - p1.x) + (p1.x - p2.x) * (p.y - p1.y);
}
void	bsp()
{
	
}