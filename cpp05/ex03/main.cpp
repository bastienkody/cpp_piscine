#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "sub_form_classes/ShrubberyCreationForm.hpp"
#include "sub_form_classes/RobotomyRequestForm.hpp"
#include "sub_form_classes/PresidentialPardonForm.hpp"

inline void	print_sep(void) {std::cout << SEP << std::endl;}
inline void	print_sep2(void) {std::cout << SEP2 << std::endl;}
inline void	print_bur(const Bureaucrat & bur) {std::cout << bur << std::endl;}
inline void	print_form(const AForm & form) {std::cout << form << std::endl;}


int	main(void)
{
	Intern intern = Intern();

	AForm * form = intern.makeForm("Shrubbery     CREATION", "at home");
	AForm * form1 = intern.makeForm("robotomyrequest", "Joey");
	AForm * form2 = intern.makeForm("PRE  SID   ENTIAL  pA  RD  On  ", "Arthur Dent");

	std::cout << "form is type : " << form->getName() << std::endl;
	std::cout << "form1 is type : " << form1->getName() << std::endl;
	std::cout << "form2 is type : " << form2->getName() << std::endl;

	try
	{
		AForm * form3 = intern.makeForm("euh c koi sa??", "Arthur Dent");
		std::cout << form3->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form;
	delete form1;
	delete form2;
}
