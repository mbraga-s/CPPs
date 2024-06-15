
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog: public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog& copy);
		Dog &operator=(const Dog& src);
		virtual ~Dog(void);

		virtual void makeSound() const;
		void	setIdea(std::string idea, int i);
		std::string	getIdea(int i) const;
				
	private:
		Brain*	_cerebrum;
};

#endif
