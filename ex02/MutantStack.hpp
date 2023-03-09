/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:02:01 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 22:20:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator riterator;
        typedef typename std::stack<T>::container_type::const_iterator citerator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator criterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        
        riterator rbegin()
        {
            return this->c.rbegin();
        }
        riterator rend()
        {
            return this->c.rend();
        }
        
        citerator cbegin()
        {
            return this->c.cbegin();
        }
        citerator cend()
        {
            return this->c.cend();
        }
        
        criterator crbegin()
        {
            return this->c.crbegin();
        }
        criterator crend()
        {
            return this->c.crend();
        }
        MutantStack(){};
        MutantStack(MutantStack const & m){*this = m;};
        MutantStack & operator=(MutantStack const & m){std::stack<T>::operator=(m); return *this;};
        ~MutantStack(){};
};

# endif