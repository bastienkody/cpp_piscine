#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define SEP_80 "----------------------------------------------------------------\
----------------"

/*	Here, we turn Animal to be an abstract class
	To do so : just define a memb function to 0 (legal in .hpp btw)
	This states that at least one function is unusable and turn the class abstract
	By convention we prefix the class by a A : AAnimal
	This kind of class is used to define templates attributes for derived class
	I yet not see many differences with an Interfaces where all of the functions
	are set to 0 -> it just declares function vs abstract that would implement some
*/

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal(const std::string type);
		AAnimal & operator=(const AAnimal &rhs);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const = 0;
		virtual Brain	*getBrain() const;
	protected:
		std::string _type;
};

std::ostream& operator<<(std::ostream& os, const AAnimal &rhs);

#endif
