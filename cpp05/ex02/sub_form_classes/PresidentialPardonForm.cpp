#include"PresidentialPardonForm.hpp"

//	Default constructor
PresidentialPardonForm::PresidentialPardonForm()
{
	_name = "";
}

//	Default destructor
PresidentialPardonForm::~PresidentialPardonForm()
{

}

//	Param constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string name)
{
	_name = name;
}

//	Copy constructor (via copy operator)
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src)
{
	*this = src;
}

//	Copy operator
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	if(this != &rhs)
	{
		_name = rhs.getName();
	}
	return (*this);
}

//	Getter on _name
std::string PresidentialPardonForm::getName() const
{
	return (_name);
}

//	Setter on _name
void PresidentialPardonForm::setName(std::string name)
{
	_name = name;
}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const PresidentialPardonForm &rhs)
{
	return (os << rhs.getName());
} 

