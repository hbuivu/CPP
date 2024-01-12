#include <iostream>

int main()
{
	int *a = new int();
	std::cout << *a << "\n";
}

/* 
NOTES:
the syntax for allocating memory and initializing int to 0 is:
int *ptr = new int(0); OR int *ptr = new int();
*/