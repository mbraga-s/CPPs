
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& copy);
		Brain &operator=(const Brain& src);
		~Brain(void);

		void	think(std::string thought, int i);
		std::string	getThought(int i) const;

	private:
		std::string	_ideas[100];
};

#endif
