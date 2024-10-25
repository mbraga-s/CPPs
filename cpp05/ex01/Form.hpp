
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int signgrade, int execgrade);
		~Form(void);
		Form(const Form &copy);
		Form &operator=(const Form &src);

		std::string getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool getFlag(void) const;

		void beSigned(const Bureaucrat &signee);

	private:
		const std::string _name;
		bool _flag;
		const int _signgrade;
		const int _execgrade;

	class GradeTooHighException: public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &src, const Form &copy);

#endif
