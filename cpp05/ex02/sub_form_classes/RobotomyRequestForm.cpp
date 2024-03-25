#include"RobotomyRequestForm.hpp"

//	Default constructor
RobotomyRequestForm::RobotomyRequestForm()
{
	_name = "";
}

//	Default destructor
RobotomyRequestForm::~RobotomyRequestForm()
{

}

//	Param constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string name)
{
	_name = name;
}

//	Copy constructor (via copy operator)
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src)
{
	*this = src;
}

//	Copy operator
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	if(this != &rhs)
	{
		_name = rhs.getName();
	}
	return (*this);
}

//	Getter on _name
std::string RobotomyRequestForm::getName() const
{
	return (_name);
}

//	Setter on _name
void RobotomyRequestForm::setName(std::string name)
{
	_name = name;
}

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const RobotomyRequestForm &rhs)
{
	return (os << rhs.getName());
} 

