#include "iter.hpp"

void	printSep(){std::cout << "------------------------------------------\n";}


void	intArr()
{
	int		arr[] = {0, 10, 22};
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<int, void>(arr, len, printEndl);
	iter<int, void>(arr, len, incr);
	iter<int, void>(arr, len, printEndl);
	printSep();
}

void	charArr()
{
	char	arr[] = {'A', 'c', 'x', 'Z'};
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<char, void>(arr, len, printEndl);
	iter<char, void>(arr, len, isUpper);
	iter<char, void>(arr, len, incr);
	iter<char, void>(arr, len, isUpper);
	printSep();
}

void	charArrNull()	//	arr == null -> no error
{
	char	arr[] = {'A', 'c', 'x'};
	char	*nul = NULL;
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<char, void>(nul, len, printEndl);
	iter<char, void>(nul, len, incr);
	iter<char, void>(nul, len, printEndl);
	printSep();
}

void	charArrLenZero()	// len == 0 -> no error
{
	char	arr[] = {'A', 'c', 'x'};

	iter<char, void>(arr, 0, printEndl);
	iter<char, void>(arr, 0, incr);
	iter<char, void>(arr, 0, printEndl);
	printSep();
}

int	main(void)
{
	intArr();
	charArr();
	charArrNull();
	charArrLenZero();
}
