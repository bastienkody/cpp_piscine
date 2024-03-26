#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<iostream>
#include<string>
#include "Bureaucrat.hpp"

/*
	Attributes grades only exist on the parent class AForm as private
	They are not inherited here.
	In order to specify them forthe child classes, we use the constructors : 
	presidential constructor calls AForm ones, in which we can specify 
	the signGrade and execGrade attributes !

	For compiling I must call the default consturctor of AForm on the
	default of presidential : I passed the AForm default constructor
	in public but the presidentyial in private : AForm can never be 
	instanciated and presdiential def constructor in uncallable
*/

class RobotomyRequestForm : public AForm
{
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

		std::string getTarget() const;

		virtual void executeForReal(Bureaucrat const & executor) const;
	private:
		RobotomyRequestForm();
		std::string _target;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &rhs);

#endif
