
#include "Base.h"
#include "Base.hpp"

Base:: ~Base()
{
	std::cout << "Base destructor called" << std::endl;
}


Base * generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0) 
	{
		std::cout << "New A" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "New B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "New C" << std::endl;
		return (new C());
	}
}

void identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr))
	{
		std::cout << "A class" << std::endl;
	}
	else if (dynamic_cast<B*>(ptr))
	{
		std::cout << "B class" << std::endl;
	}
	else if (dynamic_cast<C*>(ptr))
	{
		std::cout << "C class" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A class" << std::endl;
		(void) a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B class" << std::endl;
			(void) b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C class" << std::endl;
				(void) c;
			}
			catch (std::exception &e)
			{
				std::cout << "Exception, not a valid type" << std::endl;
			}
		}
	}
}
