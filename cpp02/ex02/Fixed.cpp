
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

/* EX02 starts here*/

bool Fixed::operator>(const Fixed& comp)
{
	return(this->_fixed_pt > comp.getRawBits());
}

bool Fixed::operator<(const Fixed& comp)
{
	return(this->_fixed_pt < comp.getRawBits());
}

bool Fixed::operator>=(const Fixed& comp)
{
	return(this->_fixed_pt >= comp.getRawBits());
}

bool Fixed::operator<=(const Fixed& comp)
{
	return(this->_fixed_pt <= comp.getRawBits());
}

bool Fixed::operator==(const Fixed& comp)
{
	return(this->_fixed_pt == comp.getRawBits());
}

bool Fixed::operator!=(const Fixed& comp)
{
	return(this->_fixed_pt != comp.getRawBits());
}

Fixed Fixed::operator+(const Fixed& src)
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed& src)
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed& src)
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed& src)
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixed_pt++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return(old);
}

Fixed &Fixed::operator--(void)
{
	this->_fixed_pt--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return(old);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	Fixed	c(a);
	Fixed	d(b);
	if(c < d)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if(a < b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	Fixed	c(a);
	Fixed	d(b);
	if(c < d)
		return (b);
	return (a);
}
