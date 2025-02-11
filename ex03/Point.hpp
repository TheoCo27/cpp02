/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:41:07 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/11 19:47:14 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__
# include "Fixed.hpp" 

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point(void);
		Point(float a, float b);
		Point(const Point& other);
		Point& operator=(const Point &other);
		~Point(void);
		Fixed const &get_x(void) const;
		Fixed const &get_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif