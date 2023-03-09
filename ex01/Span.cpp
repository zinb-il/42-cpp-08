/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:11:02 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 22:44:47 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

int s_abs(int n){return std::abs(n);}

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Span::Span()
{
    // std::cout << "Span Default constructor called" << std::endl;
}

Span::Span(std::size_t n):_size(n)
{
    // std::cout << "Span Parameter constroctur called" << std::endl;
    _tab.reserve(n);
}

Span::Span(Span const & ob)
{
    // std::cout << "Span Copy constroctur called" << std::endl;
    *this = ob;
}

Span::~Span()
{
    // std::cout << "Span Destructor called" << std::endl;
}

/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/


Span & Span::operator=(Span const & ob)
{
    // std::cout << "Span Copy assignment operator called" << std::endl;
    if (ob.getSize() > _size)
        throw Span::SizeLimit();
    _size = ob.getSize();
    _tab = ob.getTab();
    return *this;
}

/********************************************************************/


/********************************************************************/
/*                          Getters functions                       */
/********************************************************************/


unsigned int    Span::getSize() const 
{
    return (_size);
}

std::vector<int>    Span::getTab() const 
{
    return (_tab);
}

/********************************************************************/


/********************************************************************/
/*                             Exceptions                           */
/********************************************************************/

const char * Span::AddElement::what() const throw ()
{
    return "Votre list est full";
}

const char * Span::DistanceException::what() const throw ()
{
    return "Il n' y a pas assez d'élément pour calculer le distance";
}

const char * Span::SizeLimit::what() const throw ()
{
    return "Vous avez depasser les limites";
}

/********************************************************************/


/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


std::vector<int>   Span::getDistnace() const
{
    std::vector<int> dis(_tab);
    if (_tab.size() > _size)
        throw Span::AddElement();
    std::adjacent_difference(_tab.begin(), _tab.end(), dis.begin());
    std::transform(dis.begin(), dis.end(), dis.begin(), s_abs);
    return (dis);
}

void    Span::addNumber(int n)
{
    if (_tab.size() >= _size)
        throw Span::AddElement();
    _tab.push_back(n);
}
void    Span::addRange(it b, it e)
{
    if (static_cast<size_t>(std::distance(b , e)) > (_size - _tab.size()))
        throw Span::AddElement();
    while(b != e)
        _tab.push_back(*b++);
}

int Span::shortestSpan()
{
    if (_tab.size() <= 1)
         throw Span::DistanceException();
    std::vector<int> dis(Span::getDistnace());
    return *(std::min_element(dis.begin(), dis.end()));
}

int Span::longestSpan()
{
    if (_tab.size() <= 1)
         throw Span::DistanceException();
    std::vector<int> dis(Span::getDistnace());
    return *(std::max_element(dis.begin(), dis.end()));
}

/********************************************************************/

