/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:11:55 by dikhalil          #+#    #+#             */
/*   Updated: 2025/11/22 23:19:43 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float floatAbs(float num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

static float triangleArea(Point const a, Point const b, Point const c)
{
    float A;
    float B;
    float C;
    float sum;
    float area;
    
    A = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
    B = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
    C = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

    sum = A + B + C;
    area = floatAbs(sum) / 2;
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float areaABC;
    float area1;
    float area2;
    float area3;
    
    areaABC = triangleArea(a, b, c);  
    area1 = triangleArea(point, b, c);  
    area2 = triangleArea(a, point, c);
    area3 = triangleArea(a, b, point);   
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return (false);
    return (areaABC == (area1 + area2 + area3));
}
