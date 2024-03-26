#include"PresidentialPardonForm.hpp"

//	Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

//	Default destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

//	Param constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5)
{ _target = target; }

//	Copy constructor (via copy operator)
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src)
{ *this = src; }

//	Copy operator
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	if(this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);
}

//	getter
std::string PresidentialPardonForm::getTarget() const
{ return(_target); }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const PresidentialPardonForm &rhs)
{
	return (os << rhs.getName() << " has targeted " << rhs.getTarget() << std::endl);
} 

//	exec for real
void PresidentialPardonForm::executeForReal() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
