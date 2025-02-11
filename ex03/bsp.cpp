/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:42:21 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/11 19:48:32 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// static bool check_within_right(Point const a, Point const b, Point const c, Point const point)
// {
// 	//check ab right
// 	Fixed x1(a.get_x()), x2(b.get_x()), x3(point.get_x());
// 	Fixed y1(a.get_y()), y2(b.get_y()), y3(point.get_y());
// 	if ((x2 - x1)*(y3 - y1) == (y2 - y1)*(x3 -x1))
// 		return (1);
// 	//check ac right
// 	x2.setRawBits(c.get_x().getRawBits());
// 	y2.setRawBits(c.get_y().getRawBits());
// 	if ((x2 - x1)*(y3 - y1) == (y2 - y1)*(x3 -x1))
// 		return (1);
// 	//check bc right
// 	x1.setRawBits(b.get_x().getRawBits());
// 	y1.setRawBits(b.get_y().getRawBits());
// 	if ((x2 - x1)*(y3 - y1) == (y2 - y1)*(x3 -x1))
// 		return (1);
// 	return (0);
// 	//check abc point (optionnal)
// }

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed x1 = a.get_x(), y1 = a.get_y();
    Fixed x2 = b.get_x(), y2 = b.get_y();
    Fixed x3 = c.get_x(), y3 = c.get_y();
    Fixed px = point.get_x(), py = point.get_y();

    // Calcul des aires orientées
    Fixed A  = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    Fixed A1 = (px - x3) * (y2 - y3) - (x2 - x3) * (py - y3);
    Fixed A2 = (x1 - x3) * (py - y3) - (px - x3) * (y1 - y3);
    Fixed A3 = (x1 - px) * (y2 - py) - (x2 - px) * (y1 - py);

    // Vérifier si le point est sur une arête
    if (A1 == 0 || A2 == 0 || A3 == 0)
    {
        return false;
    }

    // Vérifier si le point est strictement à l'intérieur
    if ((A1 > 0 && A2 > 0 && A3 > 0) || (A1 < 0 && A2 < 0 && A3 < 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
