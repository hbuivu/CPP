#include "RPN.hpp"

int main(int argc, char **argv)
{

	std::stack<int> stack;
	if (argc != 2)
	{
		std::cerr << "Usage:: ./RPN \"statement\"\n";
		return (1);
	}
	try
	{
		RPN::calcRPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}