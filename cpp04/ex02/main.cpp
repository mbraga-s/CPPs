
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "---DOG CLASS---" << std::endl;
	{
		Dog	a;
		Dog b;

		std::cout << std::endl << "Type: " << a.getType() << std::endl;
		a.setIdea("Food", 2);
		std::cout << "Though a: " << a.getIdea(2) << std::endl;
		std::cout << "Though b: " << b.getIdea(2) << std::endl;
		b = a;
		std::cout << "Though b: " << b.getIdea(2) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << "---CAT CLASS---" << std::endl;
	{
		Cat	a;
		Cat b;

		std::cout << std::endl << "Type: " << a.getType() << std::endl;
		a.setIdea("Evil", 2);
		std::cout << "Though a: " << a.getIdea(2) << std::endl;
		std::cout << "Though b: " << b.getIdea(2) << std::endl;
		b = a;
		std::cout << "Though b: " << b.getIdea(2) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << "---AAnimal ARRAY---" << std::endl;
	AAnimal* array[4];
	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << "Array[" << i << "] is type: " << array[i]->getType() << std::endl << std::endl;
	}
	for (int i = 1; i <= 4; i++)
	{
		std::cout << std::endl;
		delete array[i];
	}
	return (0);
