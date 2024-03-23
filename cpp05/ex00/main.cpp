#include "Bureaucrat.hpp"

inline void	print_sep(void) {std::cout << SEP << std::endl;}
inline void	print_bur(const Bureaucrat & bur) {std::cout << bur << std::endl;}

int	main(void)
{
	try
	{
		Bureaucrat bur = Bureaucrat("ko", 0);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();

	try
	{
		Bureaucrat bur = Bureaucrat("ko", 151);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();

	Bureaucrat bur = Bureaucrat("jo", 45);
	try
	{
		while (true)
		{
			bur.inCrementGrade();
			print_bur(bur);
		}
	}
	catch (const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		while (true)
		{
			bur.deCrementGrade();
			print_bur(bur);
		}
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();

/*	Here is a matter : an object created inside a try/catch is not seen 
	as defined later, bc the compiler see that it can throw an exception
	and	the object is not constructed.

	try
	{
		Bureaucrat blabla = Bureaucrat("blabla", 0);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		while (true)
		{
			blabla.deCrementGrade();
			print_bur(blabla);
		}
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();
*/
}
