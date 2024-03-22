#include "Bureaucrat.hpp"

void	print_bur(const Bureaucrat & bur) {std::cout << bur << std::endl;}

int	main(void)
{
	Bureaucrat bur = Bureaucrat("jo", 45);

	print_bur(bur);

	bur.inCrementGrade();
	print_bur(bur);
 
	bur.inCrementGrade();
	print_bur(bur);

	bur.deCrementGrade();
	print_bur(bur);
}
