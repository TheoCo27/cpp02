/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:48:03 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/11 19:50:17 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{

}

Point::Point(float a, float b) : x(a), y(b)
{

}
Point::Point(const Point& other) : x(other.x), y(other.y)
{

}
Point& Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}
Point::~Point(void)
{
	// std::cout << "destructor called" << std::endl;
}
Fixed const &Point::get_x(void) const
{
	return (x);
}
Fixed const &Point::get_y(void) const
{
	return (y);
}
