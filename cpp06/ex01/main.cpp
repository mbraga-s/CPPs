
#include "Serializer.hpp"

int main()
{
	Data data;
	
	data.acc_nbr = 12345;
	data.acc_name = "Mr. Dent";

	std::cout << "--- Original ---" << std::endl;
	std::cout << "Account value:" << data.acc_nbr << std::endl;
	std::cout << "Account name:" << data.acc_name << std::endl << std::endl;

	std::cout << "Serializing..." << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);

	std::cout << "Deserializing..." << std::endl << std::endl;;
	Data *temp = Serializer::deserialize(ptr);

	std::cout << "--- After serialization / deserialization ---" << std::endl;
	std::cout << "Account value (Data):" << data.acc_nbr << std::endl;
	std::cout << "Account name (Data):" << data.acc_name << std::endl << std::endl;
	std::cout << "Account value (Temp):" << temp->acc_nbr << std::endl;
	std::cout << "Account name (Temp):" << temp->acc_name << std::endl << std::endl;

	if (temp == &data)
        std::cout << "Both pointers match - Operation sucessfull." << std::endl;
	else
		std::cout << "Pointers differ - Operation unsucessfull." << std::endl;
}