#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define SEP_80 "----------------------------------------------------------------\
----------------"

/*	How Animal pointer would acces derived class function and private attributes ?
	- Animal is not expected to declare a Brain * inside its class (subject : dog/cat have private brain)
	So Animal does not know that its derived classes have am attribute brain.
	- Maybe he could just declare a generic function (like a getter to brain) 
	that its derived classes would overwrite with their own implementation. The 
	problem is this getter might return a Brain *, but Animal does not have one.
	It can return a new brain, but what would it be? no sense. However, this is a pointer,
	so we can simply return NULL. Calling getBrain sur une vraie instance de 
	animal retournera alors NULL ; animal n'aura pas de brain. (merci Eric pour l'idee)
	Then I had a very good idea : lets make it unusable : 
	But this would make Animal abstract which is expected for ex02, not in here.
*/

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
		virtual Brain	*getBrain() const;
	protected:
		std::string _type;
};

std::ostream& operator<<(std::ostream& os, const Animal &rhs);

#endif
