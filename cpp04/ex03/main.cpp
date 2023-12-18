#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


// SUBJECT MAIN
/*
int main()
{
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
*/


int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(NULL);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("dont exist");
	if (tmp)
		me->equip(tmp);
	else
		std::cerr << "Create Materia on smthg unrecognized did not work" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "-----------------------------" << std::endl;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);		// out of range but no msg error
	std::cout << "-----------------------------" << std::endl;


	me->unequip(3);
	me->use(3, *bob);		// no equipment in slot 3, but no error msg (cf subject)
	std::cout << "-----------------------------" << std::endl;

	ICharacter* copyme = new Character(reinterpret_cast<const Character&>(*me));
	*copyme = *me;			// deep copy for _inventory
	copyme->use(0, *bob);
	copyme->use(1, *bob);
	copyme->use(2, *bob);
	copyme->use(3, *bob);
	copyme->use(4, *bob);	// out of range but no msg error
	std::cout << "-----------------------------" << std::endl;

	
	delete bob;
	delete me;
	delete copyme;
	delete src;
	delete tmp;

	return 0;
}
