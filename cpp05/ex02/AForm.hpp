#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		class UnsignedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		~AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm & src);
		AForm & operator=(const AForm & rhs);

		virtual std::string	getName() const;
		virtual int			getSignGrade() const;
		virtual int			getExecGrade() const;
		virtual int			getIsSigned() const;

		virtual void		beSigned(Bureaucrat bur) = 0;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		virtual void		executeForReal(Bureaucrat const & executor) const;

	private:
		AForm();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm &rhs);

#endif
