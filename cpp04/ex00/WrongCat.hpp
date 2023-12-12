#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat(const std::string type);
		WrongCat & operator=(const WrongCat &rhs);
		void	makeSound() const;
};

#endif