#ifndef BASE_HPP
#define BASE_HPP

#include<iostream>
#include<string>

class Base
{
	public:

		virtual ~Base();

		static	Base * generate(void);
		static	void identify(Base *p);
		static	void identify(Base & p);

	private:

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// to show error mgmt
class D : public Base {};


#endif
