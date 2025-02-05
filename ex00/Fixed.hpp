/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:43 by theog             #+#    #+#             */
/*   Updated: 2025/02/05 17:46:11 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _RawBits;
    public:
        Fixed(void);
        Fixed(int f_value);
        Fixed(const Fixed& to_copy);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif