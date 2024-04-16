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

//	getter on specific index of _vect
int		Span::getNumber(const uint i) const
{
	if (i > _max)
		throw BadIndex();
	return _vect[i];
}

//	add single number (iterator range is templated in .hpp)
void	Span::addNumber(const int nb)
{
	if (_vect.size() < _max)
		_vect.push_back(nb);
	else
		throw NoSpaceLeft();
}

//	exception
const char* Span::NoSpaceLeft::what() const throw()
{ return ("Storage capacity is full"); }
const char* Span::NeedAtLeastTwoValues::what() const throw()
{ return ("Cannot perform span with less than two values"); }
const char* Span::BadIndex::what() const throw()
{ return ("Bad index"); }

//	array triee, on y stocke les differences, on ret la + petite except la 1ere
int		Span::shortestSpan() const
{
	if (_vect.size() < 2)
		throw NeedAtLeastTwoValues();

	std::vector<int>	tmp = _vect;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());

	return *std::min_element(tmp.begin() + 1, tmp.end()) ;
}

//	array triee : on ret (biggest - smallest)
int		Span::longestSpan() const
{
	if (_vect.size() < 2)
		throw NeedAtLeastTwoValues();

	std::vector<int>	tmp = _vect;
	std::sort(tmp.begin(), tmp.end());

	return tmp.back() - tmp.front();
}
