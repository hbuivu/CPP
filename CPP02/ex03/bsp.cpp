/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:03 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 15:13:05 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed	absVal(Fixed num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

Fixed	TrArea(Point& p1, Point& p2, Point& p3)
{
	// std::cout << "1->" << p1.x * (p2.y - p3.y) << std::endl;
	// std::cout << "2->" << p2.x * (p3.y - p1.y) << std::endl;
	// std::cout << "3->" << p3.x * (p1.y - p2.y) << std::endl;

	return absVal((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y))/2);
}


bool	BSP(Triangle& t, Point& p)
{
	Fixed totalArea = TrArea(t.p1, t.p2, t.p3);
	Fixed area1 = TrArea(t.p1, t.p2, p);
	Fixed area2 = TrArea(t.p2, t.p3, p);
	Fixed area3 = TrArea(t.p3, t.p1, p);

	std::cout << "totalArea: " << totalArea << "\n";
	std::cout << "area1: " << area1 << "\n";
	std::cout << "area2: " << area2 << "\n";
	std::cout << "area3: " << area3 << std::endl;
	
	Fixed epsilon(.001f);

	return (absVal(totalArea - (area1 + area2 + area3)) <= epsilon);
}