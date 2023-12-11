#include <string>
#include <iostream>

//a ref is an alias for an existing object - ex: int x = 5, int& ref = x;
/*
refs must be bound to a modifiable object (so no const var, etc)
refs cannot be changed to refer to another object
refs are not objects
a dangling ref is when the object the ref is referring to is destroyed before the ref. undef behavior
*/

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "The memory address of str is: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;
	std::cout << "The value of str is: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;


}