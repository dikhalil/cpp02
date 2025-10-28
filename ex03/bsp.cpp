/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:11:55 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/28 14:00:41 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed absFixed(const Fixed &num)
{
    if (num < Fixed(0))
        return (Fixed(0) - num);
    return (num);
}

Fixed triangleArea(Point const a, Point const b, Point const c)
{
    Fixed A;
    Fixed B;
    Fixed C;
    Fixed sum;
    Fixed area;
    
    A = a.getX() * (b.getY() - c.getY());
    B = b.getX() * (c.getY() - a.getY());
    C = c.getX() * (a.getY() - b.getY());

    sum = A + B + C;
    area = absFixed(sum) / Fixed(2);
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC;
    Fixed area1;
    Fixed area2;
    Fixed area3;
    
    areaABC = triangleArea(a, b, c);  
    area1 = triangleArea(point, b, c);  
    area2 = triangleArea(a, point, c);
    area3 = triangleArea(a, b, point);   
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return (false);
    return (areaABC == (area1 + area2 + area3));
}
