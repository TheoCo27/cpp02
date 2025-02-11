/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:43 by theog             #+#    #+#             */
/*   Updated: 2025/02/11 20:59:25 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
# define _MaxInt 8388607
# define _MinInt -8388608

class Fixed
{
    private:
        int _RawBits;
        static const int _Nb_decimal_bits;
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

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif