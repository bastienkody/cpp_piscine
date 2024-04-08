#include "Base.hpp"

int	main(void)
{
	Base	*ptr	= Base::generate();

	Base::identify(ptr);
	Base::identify(*ptr);


//	Error tests
	Base	*nul	= NULL;
	Base	*d		= new D(); 

	Base::identify(nul);
	Base::identify(d);
	Base::identify(*d);
}