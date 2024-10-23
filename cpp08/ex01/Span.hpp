
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <climits>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span& copy);
		~Span(void);
		Span &operator=(const Span& src);
	
		void addNumber(int nbr);
		int shortestSpan(void);
		int longestSpan(void);

		void addNumbers(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end);

	private:
		unsigned int _N;
		std::vector<int> _vec;
		Span(void);

		class SpanFull : public std::exception 
		{
			public:
				const char* what() const throw()
				{
					return ("Error: Span is full");
				}
		};

		class InvalidSize : public std::exception 
		{
			public:
				const char* what() const throw()
				{
					return ("Error: Invalid array size");
				}
		};
};

#endif