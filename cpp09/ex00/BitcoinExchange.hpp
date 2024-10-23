
#ifndef BITCOIN_HPP
# define BITCOIN_CPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange& src);

		template <typename T>
		T getValue(std::string date);

		template <typename T>
		std::string getDate(T);

	private:
		std::map<std::string, int> _database;
};

#endif
