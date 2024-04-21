#include "iter.hpp"

void	printSep(){std::cout << "------------------------------------------\n";}


void	intArr()
{
	int		arr[] = {0, 10, 22};
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<int>(arr, len, print<const int>); std::cout << std::endl;
	iter<int>(arr, len, incr<int>);
	iter<int>(arr, len, print<const int>); std::cout << std::endl;
	iter<int>(arr, len, decr<int>);
	iter<int>(arr, len, print<const int>); std::cout << std::endl;
	printSep();
}

void	charArr()
{
	char	arr[] = {'A', 'c', 'x', 'Z'};
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<char>(arr, len, print<const char>); std::cout << std::endl;
	iter<char>(arr, len, isUpper<const char>);
	iter<char>(arr, len, incr<char>);
	iter<char>(arr, len, isUpper<const char>);
	printSep();
}

void	charArrNull()	//	arr == null -> no error
{
	char	arr[] = {'A', 'c', 'x'};
	char	*nul = NULL;
	size_t	len = sizeof(arr) / sizeof(arr[0]);

	iter<char>(nul, len, printEndl<const char>);
	iter<char>(nul, len, incr<char>);
	iter<char>(nul, len, printEndl<const char>);
	printSep();
}

void	charArrLenZero()	// len == 0 -> no error
{
	char	arr[] = {'A', 'c', 'x'};

	iter<char>(arr, 0, printEndl<const char>);
	iter<char>(arr, 0, incr<char>);
	iter<char>(arr, 0, printEndl<const char>);
	printSep();
}

int	main(void)
{
	intArr();
	charArr();
	charArrNull();
	charArrLenZero();
}
