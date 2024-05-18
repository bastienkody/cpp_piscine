#include <string>
#include <iostream>

typedef unsigned int uint;

void	jacobPrint(uint anteprev=0, uint prev=1, uint index=1)
{
	uint	nb = prev + anteprev * 2;

	if (index == 1)
		std::cout << 'i' << index << " - " << 0 << std::endl;
	else if (index == 2)
		std::cout << 'i' << index << " - " << 1 << std::endl;
	else if (index == 3)
		std::cout << 'i' << index << " - " << 1 << std::endl;
	else if (prev > nb)
	{
		std::cout << "\033[5mOverflow baby use more bits please\033[0m" << std::endl; 
		return ;
	}
	else
		std::cout << 'i' << index << " - " << nb << std::endl;
	jacobPrint(prev, nb, ++index);
}

int	main(void)
{
	jacobPrint();
	return 0;
}
