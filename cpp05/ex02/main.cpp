#include "Bureaucrat.hpp"
#include "sub_form_classes/ShrubberyCreationForm.hpp"
#include "sub_form_classes/RobotomyRequestForm.hpp"
#include "sub_form_classes/PresidentialPardonForm.hpp"

inline void	print_sep(void) {std::cout << SEP << std::endl;}
inline void	print_sep2(void) {std::cout << SEP2 << std::endl;}
inline void	print_bur(const Bureaucrat & bur) {std::cout << bur << std::endl;}
inline void	print_form(const AForm & form) {std::cout << form << std::endl;}

/*

*/

int	main(void)
{
	Bureaucrat	bur1 = Bureaucrat("level1", 1);
	Bureaucrat	bur6 = Bureaucrat("level6", 6);
	Bureaucrat	bur48 = Bureaucrat("level48", 48);
	Bureaucrat	bur138 = Bureaucrat("level138", 138);

	PresidentialPardonForm	pres = PresidentialPardonForm("Arthur Dent");	// sign : 25 - exec : 5
	RobotomyRequestForm		robot = RobotomyRequestForm("Arthur Dent");		// sign : 72 - exec : 45
	ShrubberyCreationForm	shrub = ShrubberyCreationForm("Mars");			// sign : 145 - exec : 137

	print_sep2();
	// 1. too low to sign
	std::cout << "1. too low to sign :" << std::endl;
	try								{ pres.beSigned(bur138); bur138.signForm(pres); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	//2. too low to sign
	std::cout << "2. too low to sign :" << std::endl;
	try								{ pres.beSigned(bur48); bur48.signForm(pres); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 3. ok to sign
	std::cout << "3. ok to sign :" << std::endl;
	try 							{ pres.beSigned(bur6); bur6.signForm(pres); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 4. ko to sign an already signed
	std::cout << "4. ko to sign an already signed :" << std::endl;
	try 							{ pres.beSigned(bur6); bur6.signForm(pres); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 5. cant exec because unsigned (exec grade ko)
	std::cout << "5. cant exec because unsigned (exec grade ko) :" << std::endl;
	try 							{ robot.execute(bur48); bur48.executeForm(robot); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 6. cant exec because unsigned (exec grade ok!)
	std::cout << "6. cant exec because unsigned (exec grade ok) :" << std::endl;
	try 							{ robot.execute(bur6); bur6.executeForm(robot); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 7. cant exec because exec grade
	std::cout << "7. cant exec because exec grade :" << std::endl;
	try 							{ pres.execute(bur48); bur48.executeForm(pres); }
	catch(const std::exception& e)	{ std::cerr << e.what() << std::endl; }
	print_sep2();

	// 8. signing remaining forms
	std::cout << "8. signing remaining forms :" << std::endl;
	try
	{
		shrub.beSigned(bur138); bur138.signForm(shrub);
		robot.beSigned(bur48); bur48.signForm(robot);
	}
	catch(const std::exception& e)	{std::cerr << e.what() << std::endl; }
	print_sep2();

	// 9. exec presidential form
	std::cout << "9. exec presidential form" << std::endl;
	pres.execute(bur1); bur1.executeForm(pres);
	print_sep2();

	// 10. exec shrubbery form
	std::cout << "10. exec shrubbery form (no output, please check *_shrubbery files)" << std::endl;
	shrub.execute(bur48); bur48.executeForm(shrub);
	print_sep2();

	// 11. exec several times robotomy (should be 50/50)
	std::cout << "11. exec several times robotomy (should be 50/50)" << std::endl;
	robot.execute(bur1); bur1.executeForm(robot); print_sep();
	robot.execute(bur1); bur1.executeForm(robot); print_sep();
	robot.execute(bur1); bur1.executeForm(robot); print_sep();
	robot.execute(bur1); bur1.executeForm(robot); print_sep();
	robot.execute(bur6); bur6.executeForm(robot); print_sep();
	robot.execute(bur6); bur6.executeForm(robot); print_sep();
	robot.execute(bur6); bur6.executeForm(robot); print_sep();
	robot.execute(bur6); bur6.executeForm(robot); print_sep();
 	print_sep2();

}
