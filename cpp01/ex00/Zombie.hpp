#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		std::string	getName() const;
		void		setName(std::string name);
		void		announce(void) const;

};

/*	extern function prototypes	*/
void	randomChump(std::string name);
void	randomChump2(std::string name);
Zombie*	newZombie(std::string name);
Zombie*	newZombie2(std::string name);

#endif
