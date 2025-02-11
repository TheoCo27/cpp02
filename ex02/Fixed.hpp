/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:43 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 14:58:19 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
    private:
        int _RawBits;
        static const int _Nb_decimal_bits;
        static const int _MaxInt = 8388607;
        static const int _MinInt = -8388608;
    public:
        Fixed(void);
        Fixed(const int f_value);
        Fixed(const float f_value);
        Fixed(const Fixed& to_copy);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool& operator>(const Fixed& other);
        bool& operator<(const Fixed& other);
        bool& operator>=(const Fixed& other);
        bool& operator<=(const Fixed& other);
        bool& operator==(const Fixed& other);
        bool& operator!=(const Fixed& other);
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);
        Fixed operator++(int value);
        Fixed& operator++(void);
        Fixed operator--(int value);
        Fixed& operator--(void);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif