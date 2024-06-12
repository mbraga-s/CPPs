
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		~Fixed(void);
		Fixed &operator=(const Fixed& src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_fixed_pt;
		const static int	_frac_bits = 8;
};

#endif
