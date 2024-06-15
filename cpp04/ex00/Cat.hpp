
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& copy);
		Cat &operator=(const Cat& src);
		virtual ~Cat(void);

		virtual void makeSound() const;
};

#endif
