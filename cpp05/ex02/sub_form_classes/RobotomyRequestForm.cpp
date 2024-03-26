#include"RobotomyRequestForm.hpp"

//	Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

//	Default destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

//	Param constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{ _target = target; }

//	Copy constructor (via copy operator)
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(const AForm & src)
{ *this = src; }

//	Copy operator
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	if(this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return (*this);
}

//	Getter on _target
std::string RobotomyRequestForm::getTarget() const
{ return (_target); }

//	os stream << redefinition
std::ostream & operator<<(std::ostream& os, const RobotomyRequestForm &rhs)
{
	return (os << rhs.getName() << " has targeted " << rhs.getTarget() << std::endl);
}

//	exec for real
void RobotomyRequestForm::executeForReal(Bureaucrat const & executor) const
{
	std::cout << "... Drrriiil Drrriiil Drrriiil ..." << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized";
	else
		std::cout << "Robotomy failed for " << this->getTarget();
	std::cout << std::endl;
}

