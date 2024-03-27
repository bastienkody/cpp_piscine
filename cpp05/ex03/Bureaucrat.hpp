#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<string>
#include "AForm.hpp"

#define SEP "----------------------------------------------------------"
#define SEP2 "##########################################################"

class AForm;

/*	
	POLYMORPHISM :
	since AForm became abstract we need to refer
	to it as a ref (or maybe a ptr) in function 
	parameter (signFrom or execForm)
	-> "const AForm & form".
	Compil error with : "Aform form".
*/

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		~Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);

		std::string getName() const;
		int			getGrade() const;

		void 		inCrementGrade();
		void 		deCrementGrade();

		void		signForm(const AForm & form);
		void		executeForm(const AForm & form);
	
	private:
		Bureaucrat();
		std::string const	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &rhs);

#endif
