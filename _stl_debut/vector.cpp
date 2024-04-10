#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
	init a vector with a size in parameter: for int, all values are set to 0
	Iterator: 
	- std::vector<int>::iterator it = it; (do not forget the typename)
	Methods:
	- insert(it, val): add value at it pos. it grow the size
	- erase(it): rm fields at it. it degrows the size
*/
void	intVector1(void)
{
	std::vector<int>	vec(10);
	std::cout << "size:\t" << vec.size() << std::endl;

	vec.insert(vec.end() - 1, 2);

	std::cout << "size:\t" << vec.size() << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " - ";
	std::cout << std::endl;

	while (!vec.empty())
		vec.erase(vec.begin());
	std::cout << "size:\t" << vec.size() << std::endl;
}

/*	
	There is no method 'find' to get n it/pos on specific value from vector,
	but we can use the one from algorithms:
	- find(it.begin(), it.end(), val): search first val from begin to end
*/
void	intVector2(void)
{
	std::vector<int>	vec(10);

	vec.insert(vec.end() - 1, 2);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " - ";
	std::cout << std::endl ;

	std::cout << "erase element 2" << std::endl;
	vec.erase(std::find(vec.begin(), vec.end(), 2));

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " - ";
	std::cout << std::endl;
}
