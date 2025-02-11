/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:48 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 19:46:31 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

void test(Point const &a, Point const &b, Point const &c, Point const &p)
{
    std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ") ";
    if (bsp(a, b, c, p))
        std::cout << "est à l'intérieur du triangle.\n";
    else
        std::cout << "n'est pas à l'intérieur du triangle.\n";
}

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    std::cout << "Triangle : A(0,0), B(10,0), C(5,10)\n";

    // Test 1 : Point à l'intérieur
    Point p1(5, 5);
    test(a, b, c, p1); // Devrait être à l'intérieur

    // Test 2 : Point sur un sommet
    Point p2(0, 0);
    test(a, b, c, p2); // Devrait être à l'extérieur (car sommet)

    // Test 3 : Point sur une arête
    Point p3(5, 0);
    test(a, b, c, p3); // Devrait être à l'extérieur (car sur une arête)

    // Test 4 : Point à l'extérieur
    Point p4(10, 10);
    test(a, b, c, p4); // Devrait être à l'extérieur

    return 0;
}
