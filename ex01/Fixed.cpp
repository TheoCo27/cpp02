/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:46 by theog             #+#    #+#             */
/*   Updated: 2025/02/10 14:44:13 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iomanip>

const int Fixed::_Nb_decimal_bits = 8;

Fixed::Fixed(void) : _RawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int f_value)
{
    std::cout << "Int constructor called" << std::endl;
    static_assert(_MaxInt <= 8388607, "Max value exceeds the allowed limit!");
    if (f_value > _MaxInt || f_value < _MinInt)
    {
        std::cerr << "Compilation error: value out of range 8,388,608!" << std::endl;
        std::exit(EXIT_FAILURE); // Arrête le programme à la compilation
    }
    _RawBits = f_value << _Nb_decimal_bits;
}
Fixed::Fixed(const float f_value)
{
    long temp;

    std::cout << "Float constructor called" << std::endl;
    if (f_value > _MaxInt || f_value < _MinInt)
    {
        std::cerr << "Compilation error: value out of range 8,388,608!" << std::endl;
        std::exit(EXIT_FAILURE); // Arrête le programme à la compilation
    }
    temp = roundf(f_value * (1 << _Nb_decimal_bits));
    if (temp > 2147483647 || temp < -2147483648) 
    {
        std::cerr << "Compilation error: Rawbits exceed int range" << std::endl;
        std::exit(EXIT_FAILURE); // Arrête le programme à la compilation
    }
    _RawBits = (int)temp;   
}
float Fixed::toFloat( void ) const
{
    return ((float)(_RawBits) / (float)(1 << _Nb_decimal_bits));
}
int Fixed::toInt( void ) const
{
    return (_RawBits >> _Nb_decimal_bits);
}
Fixed::Fixed(const Fixed& to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_RawBits = other.getRawBits();

    }
    return (*this);
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_RawBits);
}
void Fixed::setRawBits(int const raw)
{   
    _RawBits = raw;
    std::cout << "SetRawBits member function called" << std::endl;
}

bool check_if_decimal(int data)
{
    int mask = 1;
    int i = 0;

    while(i < 8)
    {
        if (data & mask)
            return (1);
        i++;
        mask = mask << 1;
    }
    return (0);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    //faire une comparaison binaire pour savoir si partie decimal vide ou non
    //out << fixed.toInt();
    if (check_if_decimal(fixed.getRawBits()) == 1)
        out << fixed.toFloat();
    else
        out << fixed.toInt();
   // out << std::fixed << std::setprecision(2) << fixed.toFloat();  // Utilisation de la méthode publique toFloat()
    return out;
}