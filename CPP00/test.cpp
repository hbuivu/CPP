#include <iostream>
#include <string>

class Test
{
public:
	static int x, y;

	static void printTest()
	{
		std::cout << x << y << '\n';
	}
};

int Test::x;
int Test::y;

int main()
{
	// Test::x = 5;
	// Test::y = 6;

	// Test::printTest();
	// return (0);

	std::cout << "Enter a name:\n";
	
	std::string str{};
	std::cin >> str;

	std::cout << "enter a number:\n";
	int	i;
	std::cin >> i;

	std::cout << str << i << '\n';

}