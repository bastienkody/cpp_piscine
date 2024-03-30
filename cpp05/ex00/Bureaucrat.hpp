#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<string>

#define SEP "----------------------------------------------------------"

/*	
	Default constructor is in PRIVATE
	It is not UNUSABLE : we need to provide
	name and grade to construct a bureaucrat
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

	private:
		Bureaucrat();
		std::string const	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &rhs);

#endif
