#ifndef TEST_HPP
#define TEST_HPP

#include<iostream>
#include<string>

class Test
{
	public:
		Test();
		~Test();
		Test(const int a, const std::string name);
		Test(const Test & src);
		Test & operator=(const Test & rhs);

		bool		operator>=(const Test & rhs);
		bool		operator<=(const Test & rhs);

		void		setNb(const int a);
		int			getNb() const;

		std::string	getName() const;

	private:
		int			_nb;
		std::string	_name;
};

std::ostream& operator<<(std::ostream& os, const Test &rhs);

#endif
