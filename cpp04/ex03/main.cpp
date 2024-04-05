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
	// FIRST PART
	std::cout << "\033[4mFIRST PART\033[m" << std::endl;

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

	delete bob;
	delete me;
	delete src;
	delete tmp;


	// SECOND PART (deep copy test)
	std::cout << "\033[4mSECOND PART\033[m" << std::endl;

	Character	*scadirac = new Character("Scadirac");
	Character	*vigier = new Character("Vigier");
	Character	*niel = new Character("Niel");

	scadirac->equip(new Ice());
	scadirac->equip(new Ice());
	scadirac->equip(new Cure());
	//scadirac->equip(new Cure()); test des copies de character avec un slot a NULL

	*vigier = *scadirac;

	vigier->use(0, *niel);
	vigier->use(1, *niel);
	vigier->use(2, *niel);
	vigier->use(3, *niel);
	std::cout << "-----------------------------" << std::endl;

	Character	*bocal= new Character(*scadirac);
	Character	bocal2(*scadirac);

	delete scadirac; // deleting scadirac let us test deep copy operator of Materia by vigier, and also via copy constructor for bocal

	vigier->use(0, *niel);
	vigier->use(1, *niel);
	vigier->use(2, *niel);
	vigier->use(3, *niel);
	std::cout << "-----------------------------" << std::endl;

	bocal->use(0, *niel);
	bocal->use(1, *niel);
	bocal->use(2, *niel);
	bocal->use(3, *niel);
	std::cout << "-----------------------------" << std::endl;

	delete vigier;
	delete bocal;
	delete niel;
}
