
#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat: public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat& copy);
		Cat &operator=(const Cat& src);
		virtual ~Cat(void);

		virtual void makeSound(void) const;
		void	setIdea(std::string idea, int i);
		std::string	getIdea(int i) const;
		
	private:
		Brain*	_cerebrum;
};

#endif
