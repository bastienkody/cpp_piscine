#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

		~Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form & src);
		Form & operator=(const Form & rhs);

		std::string getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		int			getIsSigned() const;

		void		beSigned(Bureaucrat bur);

	private:
		Form();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;

};

std::ostream& operator<<(std::ostream& os, const Form &rhs);

#endif
