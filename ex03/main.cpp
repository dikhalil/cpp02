/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:40:51 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/31 18:31:08 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point inside(1, 1);
    Point outside(5, 5);
    Point onEdge(0, 2);
    
    std::cout << "Triangle vertices: A(0,0), B(5,0), C(0,5)\n";
    std::cout << "Point (1,1) is ";
    if (bsp(a, b, c, inside))
        std::cout << "inside\n";
    else
        std::cout << "outside\n";
    std::cout << "Point (5,5) is ";
    if (bsp(a, b, c, outside))
        std::cout << "inside\n";
    else
        std::cout << "outside\n";
    std::cout << "Point (0,2) is " ;
    if (bsp(a, b, c, onEdge))
        std::cout << "inside\n";
    else
        std::cout << "outside\n";
    return (0);
}