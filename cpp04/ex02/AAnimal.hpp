
#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal& copy);
		AAnimal &operator=(const AAnimal& src);
		virtual ~AAnimal(void);

		virtual void makeSound(void) const = 0;
		std::string	getType(void) const;

	protected:
		std::string	type;
};

#endif
