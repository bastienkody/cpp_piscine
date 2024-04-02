#include<iostream>
#include<string>


/*
	What is a size_type? 

	1 - I get that type from the return of a std::string.find('c'). 
	--> it seems it is a normal index. (I get the first pos of char c index)

	2 - Is it compatible with iterator? 
	--> not directly, but no compile error !
	However, you can compare : *it (deref iterator) with str[size_type] which
	actually compares the underlying chars
*/

int	main(void)
{
	std::string	str("Salut . les gars");

	// 1
	std::string::size_type point_pos = str.find('.');
	std::cout << point_pos << std::endl;

	// 2
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == point_pos)
			std::cout << *it << " with *it == point_pos"<< std::endl;
		if (*it == str[point_pos])
			std::cout << *it << " with *it == str[point_pos]" << std::endl;
	}
}