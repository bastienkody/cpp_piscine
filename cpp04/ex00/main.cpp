#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"



/*	
	CUSTOM MAIN, using param constructor and ostream << overload redefinition
	Allocation are protected with catching std::bad_alloc + using std::exit()
*/

int	main(void)
{
{
	Animal	animal("any animal");

	animal.makeSound();
	std::cout << animal << std::endl;
}
	std::cout << "-----------------------------------" << std::endl;


	try
	{
		const Animal *ptrCat = new Cat("Le petit chaton trop mignon");

		ptrCat->makeSound();
		std::cout << *ptrCat << std::endl; // using Animal ostream<< redefinition !!
		delete ptrCat;
		std::cout << "-----------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	

	try
	{
		const Animal *ptrDog = new Dog("Snoop doggy dog");

		ptrDog->makeSound();
		std::cout << *ptrDog << std::endl;
		delete ptrDog;
		std::cout << "-----------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	
	try
	{
		const WrongAnimal *ptrWrong = new WrongCat();

		ptrWrong->makeSound();
		std::cout << *ptrWrong << std::endl;
		delete ptrWrong;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


/*	
	Alloc failure 
	try
	{
		unsigned long long int size = 21474836479999999;
		const Animal *ptrDog = new Dog [size];

		ptrDog->makeSound();
		std::cout << *ptrDog << std::endl;
		delete [] ptrDog;
		std::cout << "-----------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	} 
*/



//	SUBJECT MAIN	
/*
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

	return 0;
}
*/