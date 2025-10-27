/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:40:54 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/27 19:56:09 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = num * (1 << _fractionalBits);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(num * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const 
{
    return (_rawBits >> _fractionalBits);
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

void Fixed::setRawBits(int rawBits)
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = rawBits;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &cout, const Fixed &obj)
{
    cout << obj.toFloat();
    return (cout);
}
