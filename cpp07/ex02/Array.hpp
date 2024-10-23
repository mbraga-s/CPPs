
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
	public:
		Array(void)
		{
			this->_array = new T[0];
			this->_size = 0;
		}
		Array(unsigned int n)
		{
			this->_array = new T[n];
			this->_size = n;
		}
		~Array(void)
		{
			delete [] this->_array;
		}
		Array(const Array& copy)
		{
			if (this != copy)
				*this = copy;
		}
		Array &operator=(const Array& src)
		{
			if (this != &src)
			{
				if (this->_array)
					delete [] this->_array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}

		unsigned int size(void)
		{
			return (this->_size);
		}

		T &operator[](unsigned int i)
		{
			if (i >= size())
				throw Array::Exception();
			return (this->_array[i]);
		}


		class Exception: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return("Error, out of range.");
				}
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif
