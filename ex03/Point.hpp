/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:12:15 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/28 13:30:59 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point(void);
        Fixed getX(void) const;
        Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif