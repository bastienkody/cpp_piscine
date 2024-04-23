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

void	copyTest(void)
{
	MutantStack<int>	m1;
	m1.push(0);
	m1.push(1);
	m1.push(2);
	std::cout << "m1:\t";
	for (MutantStack<int>::iterator it = m1.begin(); it!= m1.end(); ++it)
		std::cout << *it << (it == m1.end() -1 ? "" : " -> ");
	std::cout << std::endl;

	MutantStack<int>	m2(m1);
	std::cout << "m2:\t";
	for (MutantStack<int>::iterator it = m2.begin(); it!= m2.end(); ++it)
		std::cout << *it << (it == m2.end()-1 ? "" : " -> ");
	std::cout << std::endl;

	MutantStack<int>	m3;
	m3 = m2;
	std::cout << "m3:\t";
	for (MutantStack<int>::iterator it = m3.begin(); it != m3.end(); ++it)
		std::cout << *it << (it == m3.end()-1 ? "" : " -> ");
	std::cout << std::endl;
}

/* 	std::List_iterator does not allow iterator arithmetic, only ++ and -- (InputOperator)
	c++98 provide std::advance(it, step), but it modifies it, i don want to
	c++11 provides std::prev(it) that i could use as std::prev(l.end())
	For the list printing (last one) I simply create a tmp last=l.end() that I 
	decrement once (--last) and check according to this tmp
*/
void	stackVsList(void)
{
	std::vector<int>	v(3, 42);
	MutantStack<int>	m;
	std::list<int>		l;

	v.push_back(-42);
	v.push_back(12);
	v.push_back(345667);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		m.push(*it);
		l.push_back(*it);
	}

	std::cout << "print vector:\t";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << (it == v.end() -1 ? "\n" : " -> ");

	std::cout << "print mutant:\t";
	for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << *it << (it == m.end() -1 ? "\n" : " -> ");

	std::cout << "print list:\t";
	std::list<int>::iterator last = l.end();
	--last;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << (it == last ? "\n" : " -> ");
}

void	reverseConstTest(void)
{
	MutantStack<int>	m;
	m.push(0);
	m.push(1);
	m.push(2);
	m.push(3);
	m.push(4);
	std::cout << "print reversed:\t";
	for (MutantStack<int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
		std::cout << *it << (it == m.rend() -1 ? "\n" : " -> ");

	MutantStack<int>::const_iterator cbeg = m.begin();
	std::cout << "print const:\t" << *cbeg << std::endl;

	MutantStack<int>::const_reverse_iterator crbeg = m.rbegin();
	std::cout << "print const reverse:\t" << *crbeg << std::endl;
}

int	main(void)
{
	if (true) {mainSubject();}
	std::cout << "###########################################" << std::endl;
	if (true) {copyTest();}
	std::cout << "###########################################" << std::endl;
	if (true) {stackVsList();}
	std::cout << "###########################################" << std::endl;
	if (true) {reverseConstTest();}
}
