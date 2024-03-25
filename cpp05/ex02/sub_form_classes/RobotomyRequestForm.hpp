#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<iostream>
#include<string>

class RobotomyRequestForm
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
		void		setName(std::string name);
		std::string getName() const;
	private:
		std::string _name;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &rhs);

#endif
