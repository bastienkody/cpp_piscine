#include <string>
#include <iostream>

#define OFFSET 0 // can be used to get real nb used in mij algo (jacob +1)

typedef unsigned int uint;

void	jacobPrint(uint anteprev=0, uint prev=1, uint index=1)
{
	uint	nb = prev + anteprev * 2;

	if (index == 1)
		std::cout << 'i' << index << " - " << 0 + OFFSET << std::endl;
	else if (index == 2)
		std::cout << 'i' << index << " - " << 1 + OFFSET << std::endl;
	else if (index == 3)
		std::cout << 'i' << index << " - " << 1 + OFFSET << std::endl;
	else if (prev > nb)
	{
		std::cout << "\033[5mOverflow baby use more bits please\033[0m" << std::endl; 
		return ;
	}
	else
		std::cout << 'i' << index << " - " << nb + OFFSET << std::endl;
	index == 3 ? jacobPrint(anteprev, prev, ++index) : jacobPrint(prev, nb, ++index);
}

int	main(void)
{
	jacobPrint();
	return 0;
}
