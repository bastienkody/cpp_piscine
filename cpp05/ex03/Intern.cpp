#include"Intern.hpp"
#include "sub_form_classes/ShrubberyCreationForm.hpp"
#include "sub_form_classes/RobotomyRequestForm.hpp"
#include "sub_form_classes/PresidentialPardonForm.hpp"

//	Default constructor
Intern::Intern() {}

//	Default destructor
Intern::~Intern() {}

//	Copy constructor (via copy operator)
Intern::Intern(const Intern & src) { *this = src; }

//	Copy operator
Intern & Intern::operator=(const Intern & rhs) { (void) rhs; return (*this); }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const Intern &rhs)
{ (void) rhs; return (os << "Intern is printed out"); } 

//	exceptions
const char* Intern::EmptyTargetException::what() const throw()
{ return ("I wont create a form for an empty target stupid Bureaucrat (EmptyTargetException)"); }

const char* Intern::UnrecognizedFormException::what() const throw()
{ return ("I wont create a unrecognized form stupid Bureaucrat (UnrecognizedFormException)"); }


/*	Create forms
	I could not compile directly with an array of ptr on functions/constructors
	So i created here 3 functions, not membersfunctions of intern (should I?)
	that returns a form of its type, allocated on the heap
	Then I have an array of ptr on these functions that calls constructors
*/
AForm* createShrubberyCreationForm(const std::string& target) 
{ return new ShrubberyCreationForm(target); }

AForm* createRobotomyRequestForm(const std::string& target) 
{ return new RobotomyRequestForm(target); }

AForm* createPresidentialPardonForm(const std::string& target) 
{ return new PresidentialPardonForm(target); }


AForm *Intern::makeForm(std::string form, const std::string & target) const
{
	const std::string okForms[3] = {"SHRUBBERYCREATION", "ROBOTOMYREQUEST", "PRESIDENTIALPARDON"};
	AForm * (*constructors[3])(const std::string&) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};

	if (target.size() == 0)
		throw EmptyTargetException();
	// normalize form param : erase spaces and uppercase.
	std::string form_normalized;
	for (std::string::iterator it = form.begin(); it != form.end(); ++it)
		if (!std::isspace(*it))
			form_normalized += std::toupper(*it);
	// compare the for param to okForms
	for (int i = 0; i < 3; ++i)
	{
		if (form_normalized.compare(okForms[i]) == 0)
		{
			std::cout << "Intern creates form " + okForms[i] << std::endl;
			AForm *form = constructors[i](target);
			return (form);
		}
	}
	throw UnrecognizedFormException();
}
