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

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
}

Fixed	dotProduct(Point p1, Point p2, Point p)
{
	return (p2.y - p1.y) * (p.x - p1.x) + (p1.x - p2.x) * (p.y - p1.y);
}
bool	bsp(Triangle& t, Point p)
{
	Fixed dot1 = dotProduct(t.p1, t.p2, p);
	Fixed dot2 = dotProduct(t.p2, t.p3, p);
	Fixed dot3 = dotProduct(t.p3, t.p1, p);

	if (dot1 >= 0 && dot2 >= 0 && dot3 >=0)
		return true;
	else if (dot1 < 0 && dot2 < 0 && dot3 < 0)
		return true;
	
	

	
}