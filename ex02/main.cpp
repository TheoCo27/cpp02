/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:48 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 21:38:03 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <bitset>

int main(void)
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	// return 0;
	Fixed a(1), b(0.5f), c(0.5f);

	if (a > b)
		std::cout << "a > b ou a vaut " << a << " et b vaut " << b << std::endl;
	if (a < b)
		std::cout << "a < b ou a vaut " << a << " et b vaut " << b << std::endl;
	if (b < a)
		std::cout << "b < a ou a vaut " << a << " et b vaut " << b << std::endl;
	if (c >= b)
		std::cout << "c <= b ou c vaut " << c << " et b vaut " << b << std::endl;
	if (c <= b)
		std::cout << "c <= b ou c vaut " << c << " et b vaut " << b << std::endl;
	if (c == b)
		std::cout << "c == b ou c vaut " << c << " et b vaut " << b << std::endl;
	if (a != b)
		std::cout << "a != b ou a vaut " << a << " et b vaut " << b << std::endl;
	
	a = a + b + c;
	std::cout << "after a = a + b + c, a = " << a << std::endl;
	a = a * a;
	std::cout << "after a * a, a = " << a << std::endl;
	a = a/a;
	std::cout << "after a / a, a = " << a << std::endl;
	a = a - a;
	std::cout << "after a - a, a = " << a << std::endl;
	a++;
	std::cout << "after a++, a = " << a << std::endl;
	a--;
	std::cout << "after a--, a = " << a << std::endl;
	++a;
	std::cout << "after ++a, a = " << a << std::endl;
	--a;
	std::cout << "after --a, a = " << a << std::endl;

	return 0;
}