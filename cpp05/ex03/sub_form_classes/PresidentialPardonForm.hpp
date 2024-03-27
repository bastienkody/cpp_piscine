#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include<iostream>
#include<string>
#include "../Bureaucrat.hpp"

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

class PresidentialPardonForm : public AForm
{
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

		std::string getTarget() const;

		virtual void executeForReal() const;

	private:
		PresidentialPardonForm();
		std::string _target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &rhs);

#endif
