#include"Form.hpp"

/*	Compil only if default constructor has init for sign and exec grades.
	No need for the bool or the string : they already call their default
	constructor ; but int is not an object and has no constructor	*/

//	Default constructor
Form::Form() : _signGrade(0), _execGrade(0) {}

//	Default destructor
Form::~Form() {}

//	Param constructor
Form::Form(const std::string name, const int signGrade, const int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

//	Copy constructor (via copy operator)
Form::Form(const Form & src) 
: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{ *this = src; }

//	Copy operator
Form & Form::operator=(const Form & rhs)
{
	if(this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

//	Getters
std::string Form::getName() const {return (_name);}
int Form::getSignGrade() const {return (_signGrade);}
int Form::getExecGrade() const {return (_execGrade);}
int Form::getIsSigned() const {return (_isSigned);}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Form &rhs)
{
	return (os << rhs.getName() << " Form, " \
	<< "is_signed = " << rhs.getIsSigned() \
	<< ", sign grade = " << rhs.getSignGrade() \
	<< ", exex grade = " << rhs.getExecGrade() \
	<< std::endl);
} 

//	exceptions
const char* Form::GradeTooHighException::what() const throw()
{return("GradeTooHighException");}

const char* Form::GradeTooLowException::what() const throw()
{return("GradeTooLowException");}

//	beSigned
void	Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	_isSigned = true;
}
