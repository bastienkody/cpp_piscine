#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


// Main idem ex01 + try to instanciate AAnimal
int	main(void)
{
/*{
	std::cout << "\033[1mAAnimal can't be instanciate\033[m" << std::endl;
	AAnimal *ptr	= new AAnimal();

	ptr->makeSound();
	delete ptr;
}*/
	// uncomment the above scop for AAnimal instanciation try


	std::cout << "\033[1mPointer AAnimal to a Cat\033[m" << std::endl;
{
	try
	{
		AAnimal *ptr	= new Cat();
		ptr->getBrain()->setIdea("first ever idea for a Cat");
		std::cout << ptr->getBrain()->getIdea(0) << std::endl;
		ptr->getBrain()->setIdea("second idea of a Cat");
		std::cout << ptr->getBrain()->getIdea(1) << std::endl;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

	std::cout << SEP_80 << std::endl;
	std::cout << "\033[1mPointer AAnimal to a Dog\033[m" << std::endl;
{
	try
	{
		AAnimal *ptr2	= new Dog();
		ptr2->getBrain()->setIdea("first ever idea for a Dog");
		std::cout << ptr2->getBrain()->getIdea(0) << std::endl;
		ptr2->getBrain()->setIdea("second idea for a Dog");
		std::cout << ptr2->getBrain()->getIdea(1) << std::endl;
		delete ptr2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

	std::cout << SEP_80 << std::endl;
	std::cout << "\033[1mCopy constructor Cat (deep brain copy)\033[m" << std::endl;
{
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
}

	std::cout << SEP_80 << std::endl;
	std::cout << "\033[1mCopy operator Dog (deep copy brain)\033[m" << std::endl;
{
	Dog dog;
	dog.getBrain()->setIdea("first idea (might appear for dog and copydog !)");
	dog.getBrain()->setIdea("second idea (might appear for dog and copydog !)");

	Dog	copydog;
	copydog.getBrain()->setIdea("This should be overwriten by copy below");
	copydog.getBrain()->setIdea("This one too !!");
	copydog = dog;
	std::cout << copydog.getBrain()->getIdea(0) << std::endl;
	std::cout << copydog.getBrain()->getIdea(1) << std::endl;
}

	std::cout << SEP_80 << std::endl;
	std::cout << "\033[1mAAnimal array\033[m" << std::endl;
{
	try
	{
		AAnimal *array[6];
		for (int i = 0; i < 3; ++i)
			array[i] = new Cat();
		for (int i = 3; i < 6; ++i)
			array[i] = new Dog();
		for (int i = 0; i < 6; ++i)
			array[i]->makeSound();
		for (int i = 0; i < 6; ++i)
			delete array[i];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
}
