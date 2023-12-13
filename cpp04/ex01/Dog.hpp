#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const std::string type);
		Dog(const Dog &src);
		Dog & operator=(const Dog &rhs);
		void	makeSound() const;
	private:
		Brain	*_brain; // a new dans les constructeurs et delete destructeurs !
};

#endif
