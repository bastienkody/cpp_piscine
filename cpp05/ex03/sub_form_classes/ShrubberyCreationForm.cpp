#include"ShrubberyCreationForm.hpp"

//	Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

//	Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//	Param constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{ _target = target; }

//	Copy constructor (via copy operator)
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src)
{ *this = src; }

//	Copy operator
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	if(this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return (*this);
}

//	Getter on _name
std::string ShrubberyCreationForm::getTarget() const
{ return (_target); }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const ShrubberyCreationForm &rhs)
{
	return (os << rhs.getName() << " has targeted " << rhs.getTarget() << std::endl);
} 

void ShrubberyCreationForm::executeForReal() const
{
	try
	{
		std::ofstream ofs;
		ofs.open((_target + "_shruberry").c_str(), std::ofstream::out | std::ofstream::trunc);
		ofs << "ASCII trees" << std::endl;
		ofs.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Could not write ASCII trees in " + _target + "_shrubbery because of " << e.what() << std::endl;
	}
	
}
