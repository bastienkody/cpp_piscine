#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &src);
		Animal(const std::string type);
		Animal & operator=(const Animal &rhs);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const;
	protected:
		std::string _type;
};

std::ostream& operator<<(std::ostream& os, const Animal &rhs);

#endif