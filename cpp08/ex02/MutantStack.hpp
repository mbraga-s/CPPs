
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		MutantStack(void)
		{
		};

		~MutantStack(void)
		{
		};

		MutantStack(const MutantStack &copy)
		{
			*this = copy;
		};

		MutantStack &operator=(const MutantStack &src)
		{
			if (this != &src)
			{
				this->c = src.c;
			}
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// https://en.cppreference.com/w/cpp/container/stack
		// https://cplusplus.com/reference/deque/deque/
		// c. accesses the underlying container inside the stack (usually deque, which has iterators)

		iterator begin() //returns iterator to the beginning of the stack
		{
			return (this->c.begin());
		};

		iterator end() //returns iterator to the end of the stack
		{
			return (this->c.end());
		};
		
		const_iterator cbegin() //returns const iterator to the beginning of the stack
		{
			return (this->c.cbegin());
		};

		const_iterator cend() //returns const iterator to the end of the stack
		{
			return (this->c.cend());
		};

		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		};

		reverse_iterator rend()
		{
			return (this->c.rend());
		};

		const_reverse_iterator crbegin()
		{
			return (this->c.crbegin());
		};
		
		const_reverse_iterator crend()
		{
			return (this->c.crend());
		};
	
};

#endif
