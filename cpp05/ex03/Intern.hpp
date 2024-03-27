#ifndef INTERN_HPP
#define INTERN_HPP

#include<iostream>
#include<string>
#include "AForm.hpp"

/*
	No parametric constructor : no attributes and not need in coplein
*/

class Intern
{
	public:
		class EmptyTargetException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class UnrecognizedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Intern();
		~Intern();
		Intern(const Intern & src);
		Intern & operator=(const Intern & rhs);

		AForm *makeForm(const std::string & form, const std::string & target) const;
};

std::ostream& operator<<(std::ostream& os, const Intern &rhs);

#endif
