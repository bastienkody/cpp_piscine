#include <vector>
#include <list>
#include <map>
#include <deque>
#include "easyfind.hpp"

#define INT_TO_FIND 12345
#define CONTAINER_SIZE 263475

void	withVector()
{
	std::cout << "Vector:\t";

	std::vector<int>	vect;
	for (uint i = 0; i <= CONTAINER_SIZE; ++i)
		vect.push_back(i);

	if (easyfind(vect, INT_TO_FIND) != vect.end())
		std::cout << *easyfind(vect, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << " - ";
	if (easyfindWithStdFind(vect, INT_TO_FIND) != vect.end())
		std::cout << *easyfindWithStdFind(vect, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << std::endl << "####################################" << std::endl;
}

void	withList()
{
	std::cout << "List:\t";
 
	std::list<int>	list;
	for (uint i = 0; i <= CONTAINER_SIZE; ++i)
		list.push_back(i);

	if (easyfind(list, INT_TO_FIND) != list.end())
		std::cout << *easyfind(list, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << " - ";
	if (easyfindWithStdFind(list, INT_TO_FIND) != list.end())
		std::cout << *easyfindWithStdFind(list, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << std::endl << "####################################" << std::endl;
}

void	withDeque()
{
	std::cout << "Deque:\t";
 
	std::deque<int>	deque;
	for (uint i = 0; i <= CONTAINER_SIZE; ++i)
		deque.push_back(i);

	if (easyfind(deque, INT_TO_FIND) != deque.end())
		std::cout << *easyfind(deque, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << " - ";
	if (easyfindWithStdFind(deque, INT_TO_FIND) != deque.end())
		std::cout << *easyfindWithStdFind(deque, INT_TO_FIND);
	else
		std::cout << "No match";
	std::cout << std::endl << "####################################" << std::endl;
}



int	main(void)
{
	if (true)	{withVector();}
	if (true)	{withList();}
	if (true)	{withDeque();}
}
