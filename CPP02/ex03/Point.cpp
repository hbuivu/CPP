/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:29:33 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 15:29:42 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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