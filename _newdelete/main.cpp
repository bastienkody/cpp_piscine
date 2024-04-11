#include <iostream>
#include <string>
//#include <cstdlib>


/*	new [0] works. it allocate 0 byte in one block. vlg sees it	if you dont delete*/
void	newZero(void)
{
	int	*ptr = new int [0];

	(void)ptr;
	delete [] ptr;
}

void	sizeofNewZero(void)
{
	int	*ptr;

	ptr = new int [0];

	std::cout << (sizeof(ptr) / sizeof(*ptr)) << std::endl;
	//delete [] ptr;
}


/*	delete [] frees any size (call to sizeof?)*/
void	deleteSeveral()
{
	int	*array = new int [15];
	delete [] array ;
}

int	main(void)
{
	if (true)	{newZero();}
	if (true)	{deleteSeveral();}
	if (true)	{sizeofNewZero();}
}

