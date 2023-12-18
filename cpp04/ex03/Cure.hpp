#ifndef CURE_HPP
#define CURE_HPP

#include <iostream> 
#include <cstdlib>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure &src);
		Cure & operator=(const Cure & rhs);
		virtual AMateria*	clone() const;
		virtual void 		use(ICharacter& target);
};

#endif
