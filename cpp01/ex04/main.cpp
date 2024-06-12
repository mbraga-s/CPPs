
#include <iostream>
#include <fstream>

int		checker(char **argv);

void	replacer(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return (0);
	}
	if (checker(argv))
		return (0);
	replacer(argv);
	return(0);
}

int	checker(char **argv)
{
	std::string infile;
	std::string s1;
	std::string s2;

	infile = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if(infile.empty() || s1.empty() || s2.empty() || !s1.compare(s2))
	{
		std::cout << "Invalid arguments." << std::endl;
		return (1);
	}
	return (0);
}

void	replacer(char **argv)
{
	std::ifstream	instream;
	std::ofstream	outstream;
	std::string 	infile;
	std::string 	s1;
	std::string 	s2;
	std::string		buff;
	int				pos;

	infile = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	instream.open(infile);
	if(!instream.is_open())
	{
		std::cout << "Error opening infile." << std::endl;
		return;
	}
	outstream.open(infile + ".replace");
	if(!outstream.is_open())
	{
		std::cout << "Error opening/creating outfile." << std::endl;
		return;
	}
	while(std::getline(instream, buff))
	{
		pos = 0;
		while (pos != std::string::npos)
		{
			pos = buff.find(s1, pos);
			if (pos >= 0)
			{
				std::cout << pos << std::endl;
				buff.erase(pos, s1.length());
				buff.insert(pos, s2);
				pos = pos +  s2.length();
			}
		}
		outstream << buff << std::endl;
	}
}
