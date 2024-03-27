#include"Intern.hpp"

//	Default constructor
Intern::Intern() {}

//	Default destructor
Intern::~Intern() {}

//	Copy constructor (via copy operator)
Intern::Intern(const Intern & src) { *this = src; }

//	Copy operator
Intern & Intern::operator=(const Intern & rhs) { return (*this); }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Intern &rhs)
{ return (os << "Intern is printed out"); } 

//	exceptions
const char* Intern::EmptyTargetException::what() const throw()
{ return ("I wont create a form for an empty target stupid Bureaucrat (EmptyTargetException)"); }

const char* Intern::UnrecognizedFormException::what() const throw()
{ return ("I wont create a unrecognized form stupid Bureaucrat (UnrecognizedFormException)"); }


//	create form
AForm *Intern::makeForm(const std::string & form, const std::string & target) const
{
	const std::string okForms[3] = {"SHRUBBERYCREATION", \
									"ROBOTOMYREQUEST", \
									"PRESIDENTIALPARDON"};

	if (target.size() == 0)
		throw EmptyTargetException();

	// normalize form param : erase spaces and uppercase.

	// compare the for param to okForms

}
