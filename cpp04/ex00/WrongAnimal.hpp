#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal(const std::string type);
		WrongAnimal & operator=(const WrongAnimal &rhs);
		std::string		getType() const;
		void			setType(std::string type);
		void			makeSound() const;
	protected:
		std::string _type;
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal &rhs);

#endif