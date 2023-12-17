#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;


#define MAX_SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_knowledge[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource & operator=(const MateriaSource & rhs);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif