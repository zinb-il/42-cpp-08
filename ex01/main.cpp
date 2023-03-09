/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:09:39 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 22:53:03 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

int main(void) 
{
    try
    {
        Span sp = Span(5);
        //Span sp1 = Span(0);
        // Span sp2 = Span(1);
        Span sp3(N);
        Span sp4(sp3);
        Span sp5(N);


        // Normal Test
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        //Empty Span
        //sp1.addNumber(0);

        //One element Span
        // sp2.addNumber(1);
        // std::cout << sp2.shortestSpan() << std::endl;

        //The N ellemt test
        for(int i = 0; i < N; i++)
            sp4.addNumber(N - i);
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
        
        //The N ellemt test
        std::vector<int> b = sp4.getTab();
        //sp5.addNumber(4);
        sp5.addRange(b.begin(),b.end());
        
        std::cout << sp5.shortestSpan() << std::endl;
        std::cout << sp5.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
