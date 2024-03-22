#include"Bureaucrat.hpp"

//	Default constructor
Bureaucrat::Bureaucrat()
{
	_name = "";
}

//	Default destructor
Bureaucrat::~Bureaucrat()
{

}

//	Param constructor
Bureaucrat::Bureaucrat(const std::string name)
{
	_name = name;
}

//	Copy constructor (via copy operator)
Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	*this = src;
}

//	Copy operator
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	if(this != &rhs)
	{
		_name = rhs.getName();
	}
	return (*this);
}

//	Getter on _name
std::string Bureaucrat::getName() const
{
	return (_name);
}

//	Setter on _name
void Bureaucrat::setName(std::string name)
{
	_name = name;
}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Bureaucrat &rhs)
{
	return (os << rhs.getName());
} 

