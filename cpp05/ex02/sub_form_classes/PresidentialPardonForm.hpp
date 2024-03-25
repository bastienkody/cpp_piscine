#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include<iostream>
#include<string>

class PresidentialPardonForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		void		setName(std::string name);
		std::string getName() const;
	private:
		std::string _name;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &rhs);

#endif
