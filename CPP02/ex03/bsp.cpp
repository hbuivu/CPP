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