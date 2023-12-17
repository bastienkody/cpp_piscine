#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


// SUBJECT MAIN
int main()
{
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	return 0;
}

/*
int	main(void)
{
	AMateria	*ice = new Ice();

	std::cout << ice->getType() << std::endl;

	AMateria	*ice2;

	ice2 = ice->clone();
	std::cout << ice2->getType() << std::endl;
}
*/