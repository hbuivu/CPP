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
	
	

	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:03 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 15:30:12 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	BSP(Triangle& t, Point& p)
{
	Fixed totalArea = TrArea(t.p1, t.p2, t.p3);
	Fixed area1 = TrArea(t.p1, t.p2, p);
	Fixed area2 = TrArea(t.p2, t.p3, p);
	Fixed area3 = TrArea(t.p3, t.p1, p);

	// std::cout << "totalArea: " << totalArea << "\n";
	// std::cout << "area1: " << area1 << "\n";
	// std::cout << "area2: " << area2 << "\n";
	// std::cout << "area3: " << area3 << std::endl;
	
	Fixed epsilon(.001f);

	return (absVal(totalArea - (area1 + area2 + area3)) <= epsilon);
}