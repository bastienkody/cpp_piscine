#include "ScavTrap.hpp"

//	Constructors of DERIVED class automatically call PARENT ones
//	using overload : copy, param and default are nicely selected
//	However, its more obvious to WRITE it down in the initialisation list,
//	(where you might also put specific data assignement for the derived class)
//	but NEVER in the body : it creates a new object!!!!

//	For operator definition (and generally any other memb function), you can't
//	have it in init list, you need to call it in the body via referring to the
//	parent class

//	Redefinition of parents function : if derived has a same named fonction as
//	its parent, it would overwrite the parent one. You can choose to call the
//	parents one via scope operator (ClapTrap::attack). 
//	Furthermore, in the parent you may add a "virtual" type for the function,
//	this would enable polymorphism and dynamic dispatch (what function to be 
//	called is deciding at runtime). If you don't, derived class function would 
//	still overwrite parents, but with static dispatch (done at compile time).

/*CHATGPT : The decision to declare a function as virtual or not depends on the
design goals and requirements of your application. Here are some considerations 
to help you decide:
	>> Use virtual when :  
Polymorphism is needed:
If you want to achieve polymorphism, allowing object of different derived classe
to be treated uniformly through a common interface, declare functions as virtual.
Overriding behavior is expected:
When you expect or desire derived classes to provide their own implementations 
of a function, use virtual. This allows for method overriding.
Base class pointers/references will be used:
If you plan to use pointers or references to the base class to refer to objects 
of derived classes, virtual functions are necessary to achieve polymorphic behavior.
	>> Avoid virtual when :
No polymorphism is needed:
If you don't need polymorphism and all objects are known at compile-time, using 
virtual functions might add unnecessary complexity.
Performance is a concern:
Virtual functions come with a small performance overhead due to the need for
dynamic dispatch. In performance-critical scenarios, this overhead might be a concern.
Avoiding potential pitfalls:
If you don't need the flexibility that polymorphism provides, and you want to 
avoid potential pitfalls such as accidental overriding or unintended dynamic 
dispatch, you might choose not to use virtual functions.
	>> Best Practices :
Design for flexibility:
If your design requires flexibility and extensibility, use virtual functions to
allow for future derived classes without modifying existing code.
Document your design decisions:
Clearly document whether a function is intended to be overridden or not. This
helps other developers understand your design intentions.
Performance considerations:
If performance crucial and polymorphism is not necessary, consider alternatives
like function ptr or templates for achieving flexibility without virtual fct
Review and maintainability:
Regularly review your design decisions based on evolving requirements.
Ensure that the use of virtual functions aligns with your project's goals.	*/

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = ""; 		// this is not needed bc ClapTrap does it already
	_hitPoints = 100;	// this is needed bc ClapTrap set it a 10
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav Parametric constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src)
{
	// Note that if I let "*this = src", the copy would have happened twice !
	std::cout << "Scav Copy constructor" << std::endl;
}

/*	Copy operator (cant be in init list)	*/
ScavTrap & ScavTrap::operator=(ScavTrap &rhs)
{
	ClapTrap::operator=(rhs); 
	std::cout << "Scav Copy operator" << std::endl;
	return (*this);			
}

/*	fct redefinition : overwrites parent (dynamic if virtual in parent; else static)	*/
void	ScavTrap::attack(const std::string& target)
{
	if (!this->checkHitPoints())
		return (static_cast<void>(std::cout << _name << " has no hit point, can't attack." << std::endl));
	if (!this->checkEnergyPoints())
		return (static_cast<void>(std::cout << _name << " has no energy point, can't attack." << std::endl));
	
	_energyPoints -=1;
	std::cout << "ScavTrap " << _name << " punched " << target << " with a oustanding power of ";
	std::cout  << _attackDamage << " damage points wich might stunt the opponent" << std::endl;
}

/*	scavtrap special fct	*/
void	ScavTrap::guardGate() const
{
	if (this->checkHitPoints())
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode (no energy point needed)" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead, he can't guard anything" << std::endl;
}