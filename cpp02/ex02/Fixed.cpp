
#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_pt(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_fixed_pt = copy._fixed_pt;
	*this = copy;
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

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_pt = nbr * (1 << this->_frac_bits);
	return;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_pt = roundf(nbr * (1 << this->_frac_bits));
	return;
}

float	Fixed::toFloat(void) const
{
	return((float)this->_fixed_pt / (float)(1 << this->_frac_bits));
}

int		Fixed::toInt(void) const
{
	return(this->_fixed_pt / (1 << this->_frac_bits));
}

std::ostream &operator<<(std::ostream& src, const Fixed& copy)
{
	src << copy.toFloat();
	return (src);
}