/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:09:39 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 22:23:38 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"

void n_iterator(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void c_iterator(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::citerator it = mstack.cbegin();
    MutantStack<int>::citerator ite = mstack.cend();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void r_iterator(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::riterator it = mstack.rbegin();
    MutantStack<int>::riterator ite = mstack.rend();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void cr_iterator(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::criterator it = mstack.crbegin();
    MutantStack<int>::criterator ite = mstack.crend();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

int main()
{
    std::cout << GRN << "Test1" << WHT << std::endl;
    n_iterator();
    std::cout << GRN << "Test2" << WHT << std::endl;
    c_iterator();
    std::cout << GRN << "Test3" << WHT << std::endl;
    r_iterator();
    std::cout << GRN << "Test4" << WHT << std::endl;
    cr_iterator();
    return 0;
}