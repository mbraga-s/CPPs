
#ifndef BITCOIN_HPP
# define BITCOIN_CPP

# include <iostream>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void init_data(std::string path);
		void parse_file(std::ifstream &instream);

		class FileErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class DataErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

	private:
		std::map<std::string, float> _database;
		int valid_date(std::string date);
		int valid_number(std::string value);
		std::map<std::string, float>::iterator get_closest(std::string date);
};

#endif
