#include"Bureaucrat.hpp"

//	Default constructor
Bureaucrat::Bureaucrat() {}

//	Default destructor
Bureaucrat::~Bureaucrat() {}

//	Param constructor
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

//	Copy constructor (via copy operator)
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name)
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

//	Getters
std::string Bureaucrat::getName() const {return (_name);}
int 		Bureaucrat::getGrade() const {return (_grade);}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Bureaucrat &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
} 

// Grades
void Bureaucrat::inCrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	--(this->_grade);
}

void Bureaucrat::deCrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	++(this->_grade);
}

//	Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw()
{return ("Bureaucrat::GradeTooLowException");}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{return ("Bureaucrat::GradeTooHighException");}

//	SignForm
void	Bureaucrat::signForm(const AForm & form)
{
	std::cout << "Bureaucrat " << getName();
	if (_grade <= form.getSignGrade())
		std::cout << " signed form " << form.getName() << std::endl;
	else 
		std::cout << " could not signed Form " << form.getName() \
		<< " because of grading : (bur=" << _grade << " vs form= " \
		<< form.getSignGrade() << ")" << std::endl;
}

//	ExecForm
void	Bureaucrat::executeForm(AForm const & form)
{
	std::cout << "Bureaucrat " << getName();
	if (form.getIsSigned() == false)
		std::cout << "could not exec because the form is not signed" << std::endl;
	else if (_grade > form.getSignGrade())
		std::cout << "could not exec because of grading" << std::endl;
	else 
		std::cout << "executed form" << std::endl;
}


