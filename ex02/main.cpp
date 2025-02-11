/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:48 by theog             #+#    #+#             */
/*   Updated: 2025/02/10 15:28:56 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <bitset>

int main(void)
{
	Fixed int_a(838861), float_a(1.7775f);
	int a = int_a.toInt();
	float b = float_a.toFloat();
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "int_a: " << int_a << std::endl;    // Affiche 17
    std::cout << "float_a: " << float_a << std::endl;
	std::cout << std::bitset<32>(float_a.getRawBits()) << std::endl;
	return 0;
}