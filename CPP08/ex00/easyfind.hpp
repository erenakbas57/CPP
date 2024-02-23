#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

class NotFound : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Not found");
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator ret = std::find(container.begin(), container.end(), n);
    if (ret == container.end())
        throw NotFound();
    return ret;
}

#endif