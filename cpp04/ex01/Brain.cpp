#include "Brain.hpp"

Brain::Brain() : _ideasCurrentLen(0)
{
	std::cout << "Brain default constructor" << std::endl;
	_ideas[0] = "";
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = src;
}

Brain & Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < rhs._ideasCurrentLen; ++i)
			_ideas[i] = rhs.getIdea(i);
		_ideasCurrentLen = rhs.getIdeasCurrentLen();
	std::cout << "Brain copy operator" << std::endl;
	}
	return (*this);
}

/*	getters	*/
unsigned int	Brain::getIdeasCurrentLen() const {return (_ideasCurrentLen);}

std::string	Brain::getIdea(unsigned int index) const
{
	if (_ideasCurrentLen == 0)
		return (std::cerr << NO_IDEA << std::endl, "");
	if (index > _ideasCurrentLen - 1)
		return (std::cerr << IDX_OUT << std::endl, "");
	return (_ideas[index]);
}

/*	setter	(ret false if _ideas full)	*/
bool		Brain::setIdea(std::string newIdea)
{
	if (_ideasCurrentLen == 100)
		return (std::cerr << IDEAS_FULL << std::endl, false);
	_ideas[_ideasCurrentLen++] = newIdea;
	return (true);
}