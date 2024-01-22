#include <stack>
#include <iostream>

int main(int argc, char **argv)
{
	std::stack<int> stack;
	if (argc < 2)
		std::cout << "error\n";
	int i = 1;
	while (argv[i])
	{
		if (argv[i] >= "0" && argv[i] <= "9")
			stack.push(argv[i] - "0");
		else if (argv[i] == "/" || argv[i] == "+" || argv[i] == "-" || argv[i] == "*")
		{
			//check stack for two numbers
			if (stack.size() < 2)
				throw Exception();
			int i = stack.top();
			stack.pop();
			int j = stack.top();
			stack.pop();
			stack.push(applyOperator(i, j, argv[i]));
			//pop off two numbers, apply operator, put back on stack
		}
		else
			throw Exception();
	} 
	if (stack.size() != 1)
		throw Exception();
	int finalValue = stack.top();
}

int applyOperator(int i, int j, std::string operator)
{
	if (operator == "+")
		return (i + j);
	if (operator == "-")
		return (i - j);
	if (operator == "*")
		return (i * j);
	if (operator == "/")
		return (i / j);
}