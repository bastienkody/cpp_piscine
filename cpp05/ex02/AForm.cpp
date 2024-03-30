#include"AForm.hpp"

/*	Compil only if default constructor has init for sign and exec grades.
	No need for the bool or the string : they already call their default
	constructor ; but int is not an object and has no constructor	*/

//	Default constructor
AForm::AForm() : _signGrade(0), _execGrade(0) {}

//	Default destructor
AForm::~AForm() {}

//	Param constructor
AForm::AForm(const std::string name, const int signGrade, const int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

//	Copy constructor (via copy operator)
AForm::AForm(const AForm & src) 
: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{ *this = src; }

//	Copy operator
AForm & AForm::operator=(const AForm & rhs)
{
	if(this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

//	Getters
std::string AForm::getName() const {return (_name);}
int AForm::getSignGrade() const {return (_signGrade);}
int AForm::getExecGrade() const {return (_execGrade);}
int AForm::getIsSigned() const {return (_isSigned);}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const AForm &rhs)
{
	return (os << rhs.getName() << " Form, " \
	<< "is_signed = " << rhs.getIsSigned() \
	<< ", sign grade = " << rhs.getSignGrade() \
	<< ", exex grade = " << rhs.getExecGrade() \
	<< std::endl);
} 

//	exceptions
const char* AForm::GradeTooHighException::what() const throw()
{return("GradeTooHighException");}

const char* AForm::GradeTooLowException::what() const throw()
{return("GradeTooLowException");}

const char* AForm::UnsignedFormException::what() const throw()
{return("UnsignedFormException");}

const char* AForm::AlreadySignedFormException::what() const throw()
{return("AlreadySignedFormException");}

//	beSigned
void	AForm::beSigned(Bureaucrat bur)
{
	if (_isSigned == true)
		throw AlreadySignedFormException();
	if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

//	execute (checks validity and call executeForReal)
void	AForm::execute(Bureaucrat const & executor) const
{
	if (_isSigned == false)
		throw UnsignedFormException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeForReal();
}

//	execute for real (to be overidden by child classes)
void	AForm::executeForReal() const
{

}

