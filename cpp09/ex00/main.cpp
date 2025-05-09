
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
		std::cout << "Error: Unable to open requested file." << std::endl;
		return (0);
	}

	BitcoinExchange bt_ex;

	try
	{
		bt_ex.init_data("data.csv");
		bt_ex.parse_file(instream);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	instream.close();
}
