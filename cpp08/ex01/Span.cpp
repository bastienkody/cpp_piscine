#include"Span.hpp"

//	Default tructor
Span::Span() {}
Span::~Span() {}

//	Param constructor
Span::Span(const unsigned int nb) : _max(nb) {}

//	Copy constructor 
Span::Span(const Span & src) {*this = src;}

//	Copy operator
Span & Span::operator=(const Span & rhs)
{
	_vect = rhs._vect;
	_max = rhs._max;
	return (*this);
}

void	Span::addNumber(const int nb)
{
	if (_vect.size() < _max)
		_vect.push_back(nb);
	else
		throw NoSpaceLeft();
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
}

//	exception
const char* Span::NoSpaceLeft::what() const throw()
{ return ("Storage capacity is full"); }
const char* Span::NeedAtLeastTwoValues::what() const throw()
{ return ("Cannot perform span with less than two values"); }
