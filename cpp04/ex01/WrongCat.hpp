
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& copy);
		WrongCat &operator=(const WrongCat& src);
		~WrongCat(void);

		void makeSound() const;
};

#endif