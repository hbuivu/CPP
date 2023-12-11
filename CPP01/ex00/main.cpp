#include "Zombie.hpp"

int main()
{
	//Stack Zombie
	Zombie z1("A");
	z1.announce();

	//Heap Zombie
	Zombie *z2 = newZombie("B");
	z2->announce();
	delete(z2);

	//randomchump
	randomChump("C");
}