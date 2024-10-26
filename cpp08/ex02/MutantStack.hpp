
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	{
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

		typedef std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
	}
};

#endif
