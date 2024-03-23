#include <iostream>

/*	NOTE THAT std::exit, std::abort etc are C++11 defined 
	--> cant use is at 42 commoncore cause we might compil with C++98
*/

/*	TESTS ON MAC INTEL for now.
	I replace std::abort by std::exit() because abort might not call destructors
	of stack allocated variable, according to cppref. 

	Try - catch : 	
	std::abort() stop the code and seems to delete what have been freed. Need 
	more tests to see if other scope allocation would also be deleted ..
	Without abort() I have leak on ptr (from the first new, before the try)
	that I can delete inside the cactch ; however the beneath code will be read.
	Two possibilities : 
	- ptr == addr and *ptr == 2 if not deleted (this means that a failure on new
	doesnot write anything into the pointer)
	- ptr == addr and *ptr = 0 if deleted (does delete always place 0 as a value
	for the pointer? is it machine spec? )
	There is no segfault but as in C trying to delete an already deleted pointer
	makes a doublefree.
	A pointer inside the same function that get something allocated elsewhere will
	be freed by std::abort() (exemple : do_some_new_to_see_if_its_deleted_by_abort)
	A pointer allocated elsewhere and not (yet) known here seems not to be deleted
	which might be a real problem (example : do_some_new_for_yourself_only())

	Very very interesting : when we std::abort in a nested function, it will
	free anything that exist in the calling functio, wether is was allocated in 
	an other scope or not (ie : fail_in_here_to_see_if_abort_delete_outer_scope())

	No throw : 
	Change behaviuour of new : does not throw bad_alloc but return nullptr. 
	It is the C version of handling bad alloc ; I dont really want to use it. 
	However it seems very convenient because you can copmpare your ptr to NULL. 
*/

std::string	*do_some_new_to_see_if_its_deleted_by_abort()
{ std::string *str = new std::string[7]; return (str); }

void do_some_new_for_yourself_only()
{ int *nb = new int[10]; }

int	*fail_in_here_to_see_if_abort_delete_outer_scope()
{
	long unsigned int	size = 2147483647 * 8;

	try
	{
		int	*ptr = new int [size];
		return ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " inside the fail_in_here function" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


int	main(void)
{
	std::string *AmIFreedToo = do_some_new_to_see_if_its_deleted_by_abort();

	long unsigned int	size = 2147483647 * 8;
	std::cout << size << std::endl;

	int	*ptr = new int [1000];
	*ptr = 2;	

	//fail_in_here_to_see_if_abort_delete_outer_scope();

	std::cout << "ptr address: "<< ptr << std::endl;
	std::cout << "ptr value: " << *ptr << std::endl;

	try
	{
		int	*ptr = new int [size];
		ptr[0] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failure to allocate bc of : " << e.what() << '\n';
		std::exit(EXIT_FAILURE);
		//delete ptr;
	}
	
	std::cout << "ptr address: "<< ptr << std::endl;
	std::cout << "ptr value: " << *ptr << std::endl;
	
	//delete ptr;
}
