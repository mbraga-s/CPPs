
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& copy);
		~Fixed(void);
		Fixed			&operator=(const Fixed& src);
		bool			operator>(const Fixed& comp);
		bool			operator<(const Fixed& comp);
		bool			operator>=(const Fixed& comp);
		bool			operator<=(const Fixed& comp);
		bool			operator==(const Fixed& comp);
		bool			operator!=(const Fixed& comp);
		Fixed			operator+(const Fixed& src);
		Fixed			operator-(const Fixed& src);
		Fixed			operator*(const Fixed& src);
		Fixed			operator/(const Fixed& src);
		Fixed			&operator++(void);
		Fixed			&operator--(void);
		Fixed			operator++(int);
		Fixed			operator--(int);
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int					_fixed_pt;
		const static int	_frac_bits = 8;
};

std::ostream &operator<<(std::ostream &src, const Fixed &copy);

#endif
