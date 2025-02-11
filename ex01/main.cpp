/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:48 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 17:52:51 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <bitset>

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
	// Fixed int_a(838861), float_a(1.7775f);
	// int a = int_a.toInt();
	// float b = float_a.toFloat();
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << "int_a: " << int_a << std::endl;    // Affiche 17
    // std::cout << "float_a: " << float_a << std::endl;
	// std::cout << std::bitset<32>(float_a.getRawBits()) << std::endl;
	// return 0;
}