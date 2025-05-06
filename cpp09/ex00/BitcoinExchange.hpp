
#ifndef BITCOIN_HPP
# define BITCOIN_CPP

# include <iostream>
# include <exception>
# include <fstream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void init_data(std::string path);

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
		std::map<std::string, int> _database;
};

#endif
