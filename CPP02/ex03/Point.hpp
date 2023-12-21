/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:32:11 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 15:32:13 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

typedef struct s_Point
{
	Fixed	x;
	Fixed	y;
}	Point;

typedef struct s_Triangle
{
	Point&	p1;
	Point&	p2;
	Point&	p3;
}	Triangle;

Fixed	absVal(Fixed num);
Fixed	TrArea(Point& p1, Point& p2, Point& p3);
bool	BSP(Triangle& t, Point& p);

#endif