#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		void		setName(std::string name);
		std::string getName() const;
	private:
		std::string _name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &rhs);

#endif
