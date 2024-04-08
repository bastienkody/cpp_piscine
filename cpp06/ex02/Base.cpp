#include "Base.hpp"

//	Default destructor
Base::~Base() {}

//	gen utils
Base *genA() { return new A();}
Base *genB() { return new B();}
Base *genC() { return new C();}


Base * Base::generate(void)
{
	Base * (* gen[3])() = {genA, genB, genC};

	std::srand(clock());
	return gen[std::rand() % 3]();
}

//	identifiy ptr
void Base::identify(Base *p)
{
	Base	*ptr = NULL;

	if ((ptr = dynamic_cast<A*>(p)))
		{std::cout << "Type class A" << std::endl; return; }
	else if ((ptr = dynamic_cast<B*>(p)))
		{std::cout << "Type class B" << std::endl; return; }
	else if ((ptr = dynamic_cast<C*>(p)))
		{std::cout << "Type class C" << std::endl; return; }
	else
		std::cout << "Type unknown" << std::endl;
}

//	identify ref
void Base::identify(Base & p)
{
	try
	{ 
		p = dynamic_cast<A&>(p);
		std::cout << "Type class A" << std::endl; 
		return;
	}
	catch(const std::exception& e) {}

	try
	{ 
		p = dynamic_cast<B&>(p);
		std::cout << "Type class B" << std::endl; 
		return;
	}
	catch(const std::exception& e) {}

	try
	{ 
		p = dynamic_cast<C&>(p);
		std::cout << "Type class C" << std::endl; 
		return;
	}
	catch(const std::exception& e) {}

	std::cout << "Unknown type" << std::endl;
}