/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:11:02 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 17:57:19 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

int s_abs(int n){return std::abs(n);}

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Span::Span()
{
    //std::cout << "Span Default constructor called" << std::endl;
}

Span::Span(std::size_t n):_size(n)
{
    //std::cout << "Span Parameter constroctur called" << std::endl;
}

Span::Span(Span const & ob)
{
    //std::cout << "Span Copy constroctur called" << std::endl;
    *this = ob;
}

Span::~Span()
{
    //std::cout << "Span Destructor called" << std::endl;
}

/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/


Span & Span::operator=(Span const & ob)
{
    if (ob.getSize() > _size)
        throw Span::SizeLimit();
    //std::cout << "Span Copy assignment operator called" << std::endl;
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
    return "Votre list est complete";
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

