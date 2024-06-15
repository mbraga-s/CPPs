
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "---ANIMAL CLASS---" << std::endl;
	{
		Animal	a;
		Animal	b(a);

		std::cout << std::endl << "Type: " << a.getType() << std::endl;
		a.makeSound();
		std::cout << std::endl;
	}
		std::cout << std::endl << "---DOG CLASS---" << std::endl;
	{
		Dog	a;
		Dog	b(a);

		std::cout << std::endl << "Type: " << a.getType() << std::endl;
		a.makeSound();
		std::cout << std::endl;
	}
		std::cout << std::endl << "---CAT CLASS---" << std::endl;
	{
		Cat	a;
		Cat	b(a);

		std::cout << std::endl << "Type: " << a.getType() << std::endl;
		a.makeSound();
		std::cout << std::endl;
	}
		std::cout << std::endl << "---POLYMORPHISM---" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* a = new Dog();
		const Animal* b = new Cat();
		const WrongAnimal* c = new WrongAnimal();
		const WrongAnimal* d = new WrongCat();
		std::cout << std::endl << "Type: " << meta->getType() << std::endl;
		meta->makeSound();
		std::cout << std::endl << "Type: " << a->getType() << std::endl;
		a->makeSound();
		std::cout << std::endl << "Type: " << b->getType() << std::endl;
		b->makeSound();
		std::cout << std::endl << "Type: " << c->getType() << std::endl;
		c->makeSound();
		std::cout << std::endl << "Type: " << d->getType() << std::endl;
		d->makeSound();
		std::cout << std::endl;
		delete (meta);
		std::cout << std::endl;
		delete (a);
		std::cout << std::endl;
		delete (b);
		std::cout << std::endl;
		delete (c);
		std::cout << std::endl;
		delete (d);
	}
	return (0);
}
