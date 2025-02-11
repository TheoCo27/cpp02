/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedNoPrint.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:46 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 21:36:11 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include "Fixed.hpp"
#include <cmath>

const int Fixed::_Nb_decimal_bits = 8;

Fixed::Fixed(void) : _RawBits(0)
{

}

Fixed::Fixed(const int f_value)
{
    if (f_value > _MaxInt || f_value < _MinInt)
    {
        std::cout << "Value out of range 8,388,607!\nValue has been reset to zero" << std::endl;
        _RawBits = 0;
		return;
    }
    _RawBits = f_value << _Nb_decimal_bits;
}

Fixed::Fixed(const float f_value)
{
    long temp;

    if (f_value > _MaxInt || f_value < _MinInt)
    {
        std::cout << "Value out of range 8,388,607!\nValue has been reset to zero" << std::endl;
        _RawBits = 0;
		return;
    }
    temp = roundf(f_value * (1 << _Nb_decimal_bits));
    if (temp > 2147483647 || temp < -2147483648) 
    {
        std::cout << "Rawbits exceed int range" << std::endl;
        std::cout << "Value has been reset to zero" << std::endl;
        _RawBits = 0;
		return;
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
    *this = to_copy;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->_RawBits = other._RawBits;

    }
    return (*this);
}
Fixed::~Fixed(void)
{
}
int Fixed::getRawBits(void) const
{
    return (_RawBits);
}
void Fixed::setRawBits(int const raw)
{
    _RawBits = raw;
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
    // if (check_if_decimal(fixed.getRawBits()) == 1)
    //     out << fixed.toFloat();
    // else
    //     out << fixed.toInt();
   // out << std::fixed << std::setprecision(2) << fixed.toFloat(); 
    // Utilisation de la méthode publique toFloat()
	out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
	return(_RawBits > other.getRawBits());
}


bool Fixed::operator<(const Fixed& other) const
{
	return(_RawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return(_RawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return(_RawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return(_RawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return(_RawBits != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

Fixed Fixed::operator++(int value)
{
	Fixed temp;

	(void)value;
	temp = *this;
	this->_RawBits++;
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	this->_RawBits++;
	return (*this);
}

Fixed Fixed::operator--(int value)
{
	Fixed temp;

	(void)value;
	temp = *this;
	this->_RawBits--;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->_RawBits--;
	return (*this);
}

Fixed& Fixed::min(Fixed& nb_a, Fixed& nb_b)
{
	if (nb_a.toFloat() > nb_b.toFloat())
		return (nb_b);
	else
		return (nb_a);
}
Fixed& Fixed::max(Fixed& nb_a, Fixed& nb_b)
{
	if (nb_a.toFloat() > nb_b.toFloat())
		return (nb_a);
	else
		return (nb_b);
}

const Fixed& Fixed::min(Fixed const &nb_a, Fixed const &nb_b)
{
	if (nb_a.toFloat() > nb_b.toFloat())
		return (nb_b);
	else
		return (nb_a);
}
const Fixed& Fixed::max(Fixed const &nb_a, Fixed const &nb_b)
{
	if (nb_a.toFloat() > nb_b.toFloat())
		return (nb_a);
	else
		return (nb_b);
}