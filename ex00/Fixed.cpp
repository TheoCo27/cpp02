/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:46 by theog             #+#    #+#             */
/*   Updated: 2025/02/05 17:58:55 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_RawBits = 8;

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// Fixed::Fixed(int f_value)
// {
//     _value = f_value;
// }
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
        this->_value = other.getRawBits();

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
    return (_value);
}
void Fixed::setRawBits(int const raw)
{   
    _value = raw;
    std::cout << "SetRawBits member function called" << std::endl;
}