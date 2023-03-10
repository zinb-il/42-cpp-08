/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:02:01 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/10 01:38:00 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef SPAN_HPP
# define SPAN_HPP

#include "Span.h"

typedef std::vector<int>::iterator it;

class Span
{
    private:
        std::size_t        _size;
        std::vector<int>    _tab;
        Span();
    public:
        Span(std::size_t n);
        ~Span();
        Span(Span const & ob);
        Span & operator=(Span const & ob);
        
        void                addNumber(int n);
        void                addRange(it b, it e);
        int                 shortestSpan();
        int                 longestSpan();
        
        unsigned int        getSize() const ;
        std::vector<int>    getTab() const ;
        std::vector<int>    getDistnace() const;
        class   AddElement : public std::exception
        {
            public :
                const char * what() const throw ();
        };

        class   DistanceException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

# endif