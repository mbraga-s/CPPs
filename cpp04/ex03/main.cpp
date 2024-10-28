
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int main()
{
	{
		std::cout << std::endl << "-- Test 1 --" << std::endl;

		Character c1("Gandalf");
		MateriaSource book;
		book.createMateria("cheese");
		book.createMateria("ice");
		book.learnMateria(new Ice());
		AMateria *scroll;
		AMateria *temp;
		scroll = book.createMateria("iced");
		c1.equip(scroll);
		scroll = new Cure();
		c1.equip(scroll);
		scroll = new Ice();
		c1.equip(scroll);
		scroll = new Ice();
		c1.equip(scroll);
		scroll = new Cure();
		c1.equip(scroll);
		temp = book.createMateria("ice");
		c1.equip(temp);
		delete temp;
		Character c2(c1);
		c2.use(3, c1);
		c1.unequip(3);
		delete scroll;
		c2.use(3, c1);
		c1.use(3, c2);
	}

	{
		std::cout << std::endl << "-- Test Subject --" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		return 0;
	}
}