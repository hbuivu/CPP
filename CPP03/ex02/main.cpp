#include "ScavTrap.hpp"

int main()
{
	// ClapTrap a = ClapTrap("Amy");
	// ClapTrap b = ClapTrap("Bob");
	// ClapTrap c = ClapTrap(b);
	// a.attack("Rob");
	// b.attack("Pamy");
	// c.attack("Ted");
	// a.takeDamage(20);
	// a.beRepaired(20);
	// b.beRepaired(2);
	// c = a;
	// c.takeDamage(5);

	ScavTrap a = ScavTrap("Tracy");
	ScavTrap b = a;
	ScavTrap c = ScavTrap("Ben");
	a.attack("Rob");
	a.guardGate();
	b.beRepaired(29);
}