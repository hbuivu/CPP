#include "FragTrap.hpp"

int main()
{
	FragTrap a("A");
	FragTrap b("B");
	FragTrap c(a);

	a.highFivesGuys();
	b.attack("C");
	b.takeDamage(50);
	c = b;
	c.beRepaired(100);
}