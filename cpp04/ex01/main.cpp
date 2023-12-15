#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/* MAIN POUR BRAIN SOLO
int	main(void)
{
	Brain		brain;
	std::string	idea;

	std::cout << brain.getIdeasCurrentLen() << std::endl;
	brain.getIdea(120);
	brain.getIdea(-12);

	for (unsigned int i = 0; i < 100; ++i)
		brain.setIdea("here is another idea");
	
	std::cout << brain.getIdeasCurrentLen() << std::endl;

	brain.setIdea("OUT OF RANGE idea");

	for (unsigned int i = 0; i < 100; ++i)
		std::cout << brain.getIdea(i) << std::endl;


	Brain	anotherBrain;
	anotherBrain = brain;

	anotherBrain.setIdea("this sohuld not work");
	for (unsigned int i = 0; i < 100; ++i)
		std::cout << anotherBrain.getIdea(i) << std::endl;

	
	Brain	yetAnotherBrain(brain);

	yetAnotherBrain.setIdea("this sohuld not work");
	for (unsigned int i = 0; i < 100; ++i)
		std::cout << yetAnotherBrain.getIdea(i) << std::endl;
}
*/

int	main(void)
{
	std::cout << "\033[1mPTR ANIMAL ON CAT\033[m" << std::endl;
	Animal *ptr	= new Cat();
	
	ptr->getBrain()->setIdea("first ever idea for a Cat");
	std::cout << ptr->getBrain()->getIdea(0) << std::endl;
	ptr->getBrain()->setIdea("second idea of a Cat");
	std::cout << ptr->getBrain()->getIdea(1) << std::endl;
	delete ptr;
	std::cout << SEP_80 << std::endl;
////////////////////////////////////////////////////////////////////////////////
	std::cout << "\033[1mPTR ANIMAL ON DOG\033[m" << std::endl;
	Animal *ptr2	= new Dog();
	
	ptr2->getBrain()->setIdea("first ever idea for a Dog");
	std::cout << ptr2->getBrain()->getIdea(0) << std::endl;
	ptr2->getBrain()->setIdea("second idea for a Dog");
	std::cout << ptr2->getBrain()->getIdea(1) << std::endl;
	delete ptr2;
	std::cout << SEP_80 << std::endl;
////////////////////////////////////////////////////////////////////////////////
	std::cout << "\033[1mCOPY CONSTRUCTOR WITH DIFFERENT BRAINS\033[m" << std::endl;
	Cat	cat;
	cat.getBrain()->setIdea("first idea");
	cat.getBrain()->setIdea("second idea");

	Cat	copycat(cat);
	std::cout << copycat.getBrain()->getIdea(0) << std::endl;
	std::cout << copycat.getBrain()->getIdea(1) << std::endl;

	cat.getBrain()->setIdea("here is another idea for cat that copy cat wont know");
	copycat.getBrain()->setIdea("this is specific to copycat");

	std::cout << "Third idea of cat : " << cat.getBrain()->getIdea(2) << std::endl;
	std::cout << "Third idea of copycat : " << copycat.getBrain()->getIdea(2) << std::endl;
	std::cout << SEP_80 << std::endl;
////////////////////////////////////////////////////////////////////////////////
	std::cout << "\033[1mCOPY OPERATOR WITH DIFFERENT BRAINS\033[m" << std::endl;
	Dog dog;
	dog.getBrain()->setIdea("first idea (might appear for dog and copy dog !)");
	dog.getBrain()->setIdea("second idea (might appear for dog and copy dog !)");

	Dog	copydog;
	copydog.getBrain()->setIdea("This should be overwriten by copy just below");
	copydog = dog;
	std::cout << copydog.getBrain()->getIdea(0) << std::endl;
	std::cout << copydog.getBrain()->getIdea(1) << std::endl;

	//std::cout << SEP_80 << std::endl;
}
