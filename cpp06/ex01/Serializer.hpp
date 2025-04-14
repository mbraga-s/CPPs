
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int	acc_nbr;
	std::string acc_name; 
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &src);
};

#endif