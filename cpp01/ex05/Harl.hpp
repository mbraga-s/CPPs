
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

	private:
		std::string	_levels[4];
		void		(Harl::*_level_f[4])(void);
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);
};

#endif
