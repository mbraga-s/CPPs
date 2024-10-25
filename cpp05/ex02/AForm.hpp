
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, int signgrade, int execgrade);
		~AForm(void);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &src);

		std::string getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool getFlag(void) const;

		void beSigned(const Bureaucrat &signee);
		void execute(Bureaucrat const &executor) const;
		virtual void action(void) const = 0;

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

	class FormNotSigned: public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &src, const AForm &copy);

#endif
