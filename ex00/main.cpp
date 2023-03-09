/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:09:39 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 21:00:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) 
{

    int nb[N];
    
    for (size_t i = 0; i < N; i++)
        nb[i] = N - i;
    
    
    std::vector<int> vec(nb, nb + (sizeof(nb) / sizeof(int)));
    std::deque<int> deq(nb, nb + (sizeof(nb) / sizeof(int)));
    std::list<int> lst(nb, nb + (sizeof(nb) / sizeof(int)));
    std::stack<int> e;

    test(vec, 11, 1);
    test(deq, 2, 2);
    test(lst, 8, 3);
    
    test(vec, N + 1, 4);
    test(deq, 'z', 5);
    test(lst, N + 2, 6);
    
    return 0;
}
