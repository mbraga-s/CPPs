
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &cont, int nmb)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), nmb);
	if (it == cont.end())
		throw std::runtime_error("Could not find the value");
	return (it);
}

#endif