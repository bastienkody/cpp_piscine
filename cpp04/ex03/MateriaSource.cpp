#include "MateriaSource.hpp"

// def
MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		_knowledge[i] = NULL;
}

// destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		if (_knowledge[i])
			delete _knowledge[i]; 
}

// copy deep
MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		_knowledge[i] = src._knowledge[i]->clone();
}

// copy operator (deep)
MateriaSource & MateriaSource::operator=(const MateriaSource & rhs)
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		_knowledge[i] = rhs._knowledge[i]->clone();
	return (*this);
}

// shallow ; if not leak in the main of the subject
void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return (static_cast<void>(std::cout << "Can't learn NULL Materia" << std::endl));
	int i = 0;
	for (; i < MAX_SLOTS; ++i)
		if (!_knowledge[i])
			break;
	if (i == 3 && _knowledge[i])
		return (static_cast<void>(std::cout << "Knowledge full (4 max)" << std::endl));
	_knowledge[i] = m;
}

// deep
AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type.compare("ice") && type.compare("cure"))
		return (std::cout << "Unknown Materia" << std::endl, static_cast<AMateria*>(NULL));
	int i = 0;
	for (; i < MAX_SLOTS; ++i)
	{
		if (_knowledge[i] != NULL && !type.compare(_knowledge[i]->getType()))
			break;
	}
	if (i == 3 && !_knowledge[i])
		return (NULL);
	return (_knowledge[i]->clone());


}
