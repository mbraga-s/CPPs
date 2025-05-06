
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (0);
	}
	std::ifstream instream(argv[1]);
	if (!instream.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (0);
	}

	BitcoinExchange bt_ex;

	try
	{
		bt_ex.init_data("data.csv");
		// while (std::getline(file, line))
		// {
			// bt_ex.printEntryValue(line);
		// }
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	instream.close();
}
