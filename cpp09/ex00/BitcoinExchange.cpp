
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->_database = copy._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_database = src._database;
	}
	return (*this);
}

int BitcoinExchange::valid_date(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (1);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (1);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (1);
	if (month == 2)
	{
		if (day > 29)
			return (1);
		else if ((year % 4 == 0) && day > 28)
			return (1);
	}
	return (0);
}

int BitcoinExchange::valid_number(std::string value)
{
	float flt_value;
	std::stringstream convert_value(value);

	convert_value >> flt_value;
	if (convert_value.fail())
	{
		std::cout << "Error: invalid value" << std::endl;
		return (1);
	}
	return (0);
}

std::map<std::string, float>::iterator BitcoinExchange::get_closest(std::string date)
{
	std::map<std::string, float>::iterator it = _database.lower_bound(date);
	if (it == _database.begin() && date != it->first)
	{
		std::cout << "Error: no exchange rate for date " << date << std::endl;
		return _database.end();
	}
	else if (it == _database.end() || date != it->first)
		--it;
	return(it);
}

void BitcoinExchange::init_data(std::string path)
{
	std::string line;
	std::size_t pos;

	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw BitcoinExchange::FileErrorException();
	while(std::getline(file, line))
	{
		pos = line.find(",");
		if(pos != std::string::npos)
		{
			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 1);
			if (date.empty() || value.empty())
			{
				file.close();
				throw BitcoinExchange::DataErrorException();
			}
			float flt = std::atof(value.c_str());
			_database.insert(std::pair<std::string, float>(date, flt));
		}
		else
		{
			file.close();
			throw BitcoinExchange::DataErrorException();
		}
	}
	file.close();
}

void BitcoinExchange::parse_file(std::ifstream &instream)
{
	std::string line;

	std::getline(instream, line);
	if (line != "date | value")
		throw BitcoinExchange::DataErrorException();
	while(std::getline(instream, line))
	{
		if(line.length() < 1)
			throw BitcoinExchange::DataErrorException();
		std::size_t pos = line.find('|');
		if (pos != std::string::npos)
		{
			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 1);

			std::size_t space_pos;
			while ((space_pos = date.find(' ')) != std::string::npos)
				date.erase(space_pos, 1);
			while ((space_pos = value.find(' ')) != std::string::npos)
				value.erase(space_pos, 1);
			
			if (valid_date(date))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			if (valid_number(value))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			float flt_value = std::atof(value.c_str());
			if (flt_value < 0 || flt_value > 1000.0)
			{
				if (flt_value < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << "Error: too large a number." << std::endl;
				continue ;
			}
			std::map<std::string, float>::iterator it = get_closest(date);
			if (it == _database.end())
				return;
			float result = it->second * flt_value;
			std::cout << it->first << " => " << it->second << " = " << result << std::endl;
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

const char *BitcoinExchange::FileErrorException::what(void) const throw()
{
	return ("Unable to open database.");
}

const char *BitcoinExchange::DataErrorException::what(void) const throw()
{
	return ("Database/Input entry not recognised.");
}
