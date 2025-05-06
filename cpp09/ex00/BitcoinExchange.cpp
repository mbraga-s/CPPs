
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

void BitcoinExchange::init_data(std::string path)
{
	std::string buff;
	std::string date;
	size_t pos;

	std::ifstream file(path);
	if (!file.is_open())
		throw BitcoinExchange::FileErrorException();
	
	while(std::getline(file, buff))
	{
		pos = buff.find(",");
		if(pos != std::string::npos)
		{
			date = buff.substr(0, pos);
			std::cout << date << std::endl;
			
		}
	}
}
