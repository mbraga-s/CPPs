
#include "Harl.hpp"

Harl::Harl(void)
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_level_f[0] = &Harl::_debug;
	_level_f[1] = &Harl::_info;
	_level_f[2] = &Harl::_warning;
	_level_f[3] = &Harl::_error;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if(level == _levels[i])
		{
			(this->*_level_f[i])();
			return;
		}
	}
	std::cout << "No level exists with that name." << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
	return;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << std::endl;
	return;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
	return;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
	return;
}
