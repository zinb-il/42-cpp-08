/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:02:01 by ziloughm          #+#    #+#             */
/*   Updated: 2023/03/09 20:59:43 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <vector>
# include <deque>
# include <list>
# include <stack>
# include <iterator>
# include <algorithm>  


#define GRN "\033[0;32m"
#define WHT "\033[0;0m"
#define RED "\033[0;31m"

#define N 100


//Exception not found 

class NotFound: public std::exception
{
    public:
        const char* what(void) const throw() {return "Élément non trouvé dans votre conteneur";};
};

//Template of easyfind
template <typename C>
int easyfind(C a, int e)
{
    typename C::iterator b = a.begin();
    typename C::iterator en = a.end();
    typename C::iterator it = std::find(b, en, e);
    if (it == en)
        throw (::NotFound());
    return std::distance(b, it);
}


//Template test

template <typename C>
void test(C a, int b, int i)
{
    std::cout << GRN << std::setfill('*') << std::setw(46);
    std::cout << "Test: " << i << std::setfill('*') << std::setw(46) << WHT << std::endl;
    try
    {
        ::easyfind(a, b);
        std::cout << "L'élément '" << b << "' est trouvé dans votre conteneur a la position " 
        << ::easyfind(a, b) + 1 << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << b << " : " << e.what() << WHT << std::endl << std::endl;
    }
}

# endif