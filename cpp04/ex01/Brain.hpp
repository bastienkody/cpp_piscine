#ifndef	BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define IDX_OUT "Ideas index requested via getIdea is out of range. You will get an empty string"
#define IDEAS_FULL "The brain is full of 100 ideas, you can't add more"
#define NO_IDEA "The brain is absolutely empty (not even a single idea)"

class	Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &src);
		Brain & operator=(const Brain &rhs);
		std::string	getIdea(unsigned int index) const;
		bool		setIdea(std::string newIdea);
		unsigned int	getIdeasCurrentLen() const;
	private:
		std::string		_ideas[100];
		unsigned int	_ideasCurrentLen;
};

#endif