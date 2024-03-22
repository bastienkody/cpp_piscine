#include"Bureaucrat.hpp"

//	Default destructor
Bureaucrat::~Bureaucrat()
{
}

//	Param constructor
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{

}

//	Copy constructor (via copy operator)
Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	*this = src;
}

//	Copy operator (IMPOSSIBLE TO ASSIGN _name SINCE IT IS CONST)
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	if(this != &rhs)
	{
		//_name = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

//	Getter on _name
std::string Bureaucrat::getName() const
{
	return (_name);
}

//	Getter on _grade
int Bureaucrat::getGrade() const
{
	return (_grade);
}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Bureaucrat &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
} 

// Increment grade
void Bureaucrat::inCrementGrade()
{
	++(this->_grade);
}

// Decrement grade
void Bureaucrat::deCrementGrade()
{
	--(this->_grade);
}
