#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include<string>

class ShrubberyCreationForm
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);
		void		setName(std::string name);
		std::string getName() const;
	private:
		std::string _name;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm &rhs);

#endif
