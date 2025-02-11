/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:46 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 17:45:20 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_Nb_decimal_bits = 8;

// constructeur

Fixed::Fixed(void) : _RawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int f_value)
{
    std::cout << "Int constructor called" << std::endl;
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

    std::cout << "Float constructor called" << std::endl;
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
Fixed::Fixed(const Fixed& to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

//operateurs canon
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_RawBits = other.getRawBits();

    }
    return (*this);
}
//destructeur
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

//getter
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_RawBits);
}

//setter
void Fixed::setRawBits(int const raw)
{   
    _RawBits = raw;
    std::cout << "SetRawBits member function called" << std::endl;
}

//fonctions d aide
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


//convertisseurs
float Fixed::toFloat( void ) const
{
	return ((float)(_RawBits) / (float)(1 << _Nb_decimal_bits));
}


int Fixed::toInt( void ) const
{
	return (_RawBits >> _Nb_decimal_bits);
}

//operateurs
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
