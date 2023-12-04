
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		std::string	getName() const;
		void		setName(std::string name);
		void		announce(void) const;
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

/*	extern function prototypes	*/
void	randomChump(std::string name);
void	randomChump2(std::string name);
Zombie*	newZombie(std::string name);
Zombie*	newZombie2(std::string name);