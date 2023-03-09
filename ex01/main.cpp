/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:09:39 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 18:03:52 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

int main(void) 
{
    try
    {
        // Span sp = Span(5);
        // Span sp1 = Span(0);
        // Span sp2 = Span(1);
        Span sp3(100000);
        Span sp4(sp3);


        //Normal Test
        // sp.addNumber(5);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;
        
        //Empty Span
        // sp1.addNumber(0);

        // //One element Span
        // sp2.addNumber(1);
        // std::cout << sp2.shortestSpan() << std::endl;

        //The N ellemt test
        for(int i = 0; i < N; i++)
        {
            sp4.addNumber(N - i);
        }
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
