#include "Zombie.hpp"

//new returns a pointer - it allocates memory and calls the constructor of the object
//use delete to free - it will call the destructor
//if allocating with square brackets, delete with square brackets
//there is also placement new - look that up later

// It creates a zombie, name it, and return it so you can use it outside of the function scope.
Zombie* newZombie (std::string name)
{
	Zombie*	newZombie = new Zombie(name);
	return (newZombie);
}