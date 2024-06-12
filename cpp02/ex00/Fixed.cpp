
#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_pt(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_pt = copy._fixed_pt;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(const Fixed& src)
{
	this->_fixed_pt = src._fixed_pt;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_pt);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_pt = raw;
	return;
}