#include"Test.hpp"

//	Default constructor
Test::Test() : _nb(0), _name("no name") {}

//	Default destructor
Test::~Test() {}

//	Param constructor
Test::Test(const int a, const std::string name) : _nb(a), _name(name) {}

//	Copy constructor (via copy operator)
Test::Test(const Test & src) { *this = src; }


//	Copy operator
Test & Test::operator=(const Test & rhs)
{
	if(this != &rhs)
	{
		_name = rhs.getName();
		_nb = rhs.getNb();
	}
	return (*this);
}

//	Getters
std::string	Test::getName() const { return (_name); }
int			Test::getNb() const { return (_nb); }

//	setters
void Test::setName(const std::string name) { _name = name; }
void Test::setNb(const int a) { _nb = a; }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Test &rhs)
{ return (os << rhs.getName() << ", with nb:" << rhs.getNb()); }
