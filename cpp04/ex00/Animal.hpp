#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		~Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		Animal & operator=(const Animal &rhs);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound();
	private:
		std::string _type;
};

#endif