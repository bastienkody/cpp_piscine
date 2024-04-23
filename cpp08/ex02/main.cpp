#include "MutantStack.hpp"
#include <list>
#include <vector>

int mainSubject()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

void	mainCustom(void)
{
	MutantStack<int>	m1;
	m1.push(0);
	m1.push(1);
	m1.push(2);
	std::cout << "m1:" << std::endl;
	for (MutantStack<int>::iterator it = m1.begin(); it!= m1.end(); ++it)
		std::cout << *it << (it == m1.end() -1 ? "" : " - ");
	std::cout << std::endl;

	MutantStack<int>	m2(m1);
	std::cout << "m2:" << std::endl;
	for (MutantStack<int>::iterator it = m2.begin(); it!= m2.end(); ++it)
		std::cout << *it << (it == m2.end()-1 ? "" : " - ");
	std::cout << std::endl;

	MutantStack<int>	m3;
	m3 = m2;
	std::cout << "m3:" << std::endl;
	for (MutantStack<int>::iterator it = m3.begin(); it != m3.end(); ++it)
		std::cout << *it << (it == m3.end()-1 ? "" : " - ");
	std::cout << std::endl;
}

void	stackVsList(void)
{
	std::vector<int>	v(10, 42);
	MutantStack<int>	m;
	std::list<int>		l;

	v.push_back(-42);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		m.push(*it);
		l.push_back(*it);
	}

	std::cout << "print vector:\t";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << (it == v.end() -1 ? "\n" : " - ");

	std::cout << "print mutant:\t";
	for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << *it << (it == m.end() -1 ? "\n" : " - ");

	std::cout << "print list:\t";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << (it == l.end() -1 ? "\n" : " - ");
}

int	main(void)
{
	if (true) {mainSubject();}
	std::cout << "###########################################" << std::endl;
	if (true) {mainCustom();}
	std::cout << "###########################################" << std::endl;
	if (true) {stackVsList();}
}
