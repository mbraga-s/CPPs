
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	public:

		static void convert(const std::string &str);

	private:

		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
};

enum input_type {CHAR, INT, FLOAT, DOUBLE, INF, ERROR};

#endif
