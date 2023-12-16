#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"

//	virtual makesound() or getBrain() -> by convention to see that it also
//	exists in an upper class but you redefine it here. 
//	vs virtual destructor which is necessary for calling all family destructors

class Cat: public AAnimal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &src);
		Cat(const std::string type);
		Cat & operator=(const Cat &rhs);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
	private:
		Brain	*_brain;
};

#endif
