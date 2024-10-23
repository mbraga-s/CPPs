
#include "Span.hpp"

Span::Span(unsigned int N): _N(N)
{
}

Span::Span(void)
{
}
Span::~Span(void)
{
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span &Span::operator=(const Span& src)
{
	if (this != &src)
	{
		_N = src._N;
		_vec = src._vec;
	}
	return (*this);
}

void Span::addNumber(int nbr)
{
	if (_vec.size() < _N)
		_vec.push_back(nbr);
	else
		throw SpanFull();
}

void Span::addNumbers(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end)
{
	for(std::vector<int>::iterator it = iter_begin; it != iter_end; it++)
		addNumber(*it);
}

int Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSize();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	int sspan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		if((sorted[i] - sorted[i - 1]) < sspan)
			sspan = (sorted[i] - sorted[i - 1]);
	}
	return (sspan);
}

int Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSize();
	int smallest = *std::min_element(_vec.begin(), _vec.end());
	int largest = *std::max_element(_vec.begin(), _vec.end());
	return (largest - smallest);
}