#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <cstdlib>
#include "AAnimal.hpp"

//	virtual makesound() or getBrain() -> by convention to see that it also
//	exists in an upper class but you redefine it here. 
//	vs virtual destructor which is necessary for calling all family destructors

class Dog: public AAnimal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const std::string type);
		Dog(const Dog &src);
		Dog & operator=(const Dog &rhs);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
	private:
		Brain	*_brain;
};

#endif
