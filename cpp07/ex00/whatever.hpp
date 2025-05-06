#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T>
T const max(T const x, T const y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

template <typename T>
T const min(T const x, T const y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

#endif
