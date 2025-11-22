/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:40:54 by dikhalil          #+#    #+#             */
/*   Updated: 2025/11/22 23:38:16 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int num)
{
    _rawBits = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
    _rawBits = roundf(num * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return ((1.0f *_rawBits) / (1 << _fractionalBits));
}
int Fixed::toInt(void) const 
{
    return (_rawBits >> _fractionalBits);
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

void Fixed::setRawBits(int rawBits)
{
    _rawBits = rawBits;
}

int Fixed::getRawBits(void) const
{
    return (_rawBits);
}

Fixed::~Fixed(void) {}

bool Fixed::operator>(const Fixed &other) const
{
    return (_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (_rawBits == other._rawBits);
}
 
bool Fixed::operator!=(const Fixed &other) const
{
    return (_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    
    result.setRawBits(_rawBits + other._rawBits);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    
    result.setRawBits(_rawBits - other._rawBits);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    
    result.setRawBits((_rawBits * other._rawBits) >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    
    result.setRawBits((_rawBits << _fractionalBits) / other._rawBits);
    return (result);
}

Fixed &Fixed::operator++(void)
{
    _rawBits++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    _rawBits--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _rawBits++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _rawBits--;
    return (tmp);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream &cout, const Fixed &obj)
{
    cout << obj.toFloat();
    return (cout);
}
