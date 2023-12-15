#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &src);
		Cat(const std::string type);
		Cat & operator=(const Cat &rhs);
		void	makeSound() const;
		Brain	*getBrain() const;
	private:
		Brain	*_brain;
};

#endif
