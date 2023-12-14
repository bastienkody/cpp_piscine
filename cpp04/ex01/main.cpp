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
	Animal *ptr	= new Cat();

	std::cout << ptr->_brain.getIdeasCurrentLen() << std::endl;
}
