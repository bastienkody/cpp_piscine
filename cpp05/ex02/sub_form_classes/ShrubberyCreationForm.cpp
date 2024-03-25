#include"ShrubberyCreationForm.hpp"

//	Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
{
	_name = "";
}

//	Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

//	Param constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
{
	_name = name;
}

//	Copy constructor (via copy operator)
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src)
{
	*this = src;
}

//	Copy operator
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	if(this != &rhs)
	{
		_name = rhs.getName();
	}
	return (*this);
}

//	Getter on _name
std::string ShrubberyCreationForm::getName() const
{
	return (_name);
}

//	Setter on _name
void ShrubberyCreationForm::setName(std::string name)
{
	_name = name;
}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const ShrubberyCreationForm &rhs)
{
	return (os << rhs.getName());
} 

