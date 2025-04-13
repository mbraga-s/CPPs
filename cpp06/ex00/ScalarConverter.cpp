
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

int get_type(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	else if (str == "inf" || str == "inff" || str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" ||  str == "-inff")
		return (INF);
	else if (str[str.length() - 1] == '.' || str[str.length() - 1] == '-' || str[str.length() - 1] == '+')
		return (ERROR);

	int	f_count = 0;
	int	d_count = 0;
	int sign_count = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f' && str[i] != '.' && str[i] != '-' && str[i] != '+')
			return (ERROR);
		if (str[i] == 'f')
			f_count++;
		else if (str[i] == '.')
			d_count++;
		else if (str[i] == '+' || str[i] == '-')
			sign_count++;

		if (str[i] == '.' && (i != str.length() - 1))
		{
			if (str[i + 1] == 'f')
				d_count++;
		}
	}

	if (f_count > 1 || d_count > 1 || sign_count > 1)
		return (ERROR);
	if (sign_count == 1 && str[0] != '+' && str[0] != '-')
		return (ERROR);
	if (f_count == 1 && str[str.length() - 1] != 'f')
		return (ERROR);
	if (d_count == 1 && (str[str.length() - 1] == '.' || str[0] == '.'))
		return (ERROR);
		
	if (f_count == 0 && d_count == 0)
		return (INT);
	else if (f_count == 0 && d_count == 1)
		return (DOUBLE);
	else if (f_count == 1 && d_count == 1)
		return (FLOAT);
	else
		return (ERROR);

}

void	is_int(const std::string &str)
{
	long int i = std::strtol(str.c_str(), NULL, 10);
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
	{
		std::cout << "Impossible conversion: Integer overflow" << std::endl;
		return ;
	}
	if ((i >= std::numeric_limits<char>::min() || i <= std::numeric_limits<char>::max()) && std::isprint(static_cast<char>(i)))
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void	is_char(const std::string &str)
{

	if (std::isprint(static_cast<char>(str[0])))
		std::cout << "char: \'" << static_cast<char>(str[0]) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void is_inf(const std::string &str) 
{
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} 
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str)
{
	switch (get_type(str))
	{
	case CHAR:
		is_char(str);
		break;
	case INT:
		is_int(str);
		break;
	case FLOAT:
		std::cout << "FLOAT" << std::endl;
		break;
	case DOUBLE:
		std::cout << "DOUBLE" << std::endl;
		break;
	case INF:
		is_inf(str);
		break;
	default:
		std::cout << "Impossible conversion: Bad syntax" << std::endl;
		break;
	}
}

