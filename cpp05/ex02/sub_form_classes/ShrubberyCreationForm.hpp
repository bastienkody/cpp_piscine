#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include<string>
#include <fstream>
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

class ShrubberyCreationForm : public AForm
{
	public:
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

		std::string getTarget() const;

		virtual void executeForReal() const;
	private:
		ShrubberyCreationForm();
		std::string _target;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm &rhs);

#endif
