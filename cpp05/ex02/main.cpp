#include "Bureaucrat.hpp"

inline void	print_sep(void) {std::cout << SEP << std::endl;}
inline void	print_sep2(void) {std::cout << SEP2 << std::endl;}
inline void	print_bur(const Bureaucrat & bur) {std::cout << bur << std::endl;}
inline void	print_form(const Form & form) {std::cout << form << std::endl;}

/*
	The signing is checked before the grading : if a form is unsigned
	I wont be checking the grading so the exception would only be unsigned
	We could have it both but it does not make sense to me. 
*/

void	bad_grades_at_construct(void)
{
	try
	{
		std::cout << "Form 151, 150 : " ;
		Form form = Form("form1", 151, 50);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();
	try
	{
		std::cout << "Form 150, 151 : " ;
		Form form = Form("form1", 150, 151);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();
	try
	{
		std::cout << "Form 0, 100 : " ;
		Form form = Form("form1", 0, 100);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();
	try
	{
		std::cout << "Form 100, 0 : " ;
		Form form = Form("form1", 100, 0);
	}	
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_sep();
}

void	too_low_to_sign()
{
	Form 		form = Form("form", 5, 100);
	Bureaucrat	bur = Bureaucrat("bur", 12);

	try
		{ form.beSigned(bur); }
	catch(const std::exception& e)
		{ std::cerr << e.what() << '\n'; }
	bur.signForm(form);
}

void	too_low_to_sign_incr()
{
	Form 		form = Form("form", 10, 100);
	Bureaucrat	bur = Bureaucrat("bur", 12);

	for (int i = 0; i<4; ++i)
	{
		try
			{ form.beSigned(bur); }
		catch(const std::exception& e)
			{ std::cerr << e.what() << '\n'; }
		bur.signForm(form);
		bur.inCrementGrade();
		print_sep();
	}
}

int	main(void)
{
	bad_grades_at_construct();
	print_sep2();
	too_low_to_sign();
	print_sep2();
	too_low_to_sign_incr();

}
