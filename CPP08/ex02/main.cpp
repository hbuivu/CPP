#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>

int main()
{
	MutantStack<int> mstack;
	std::deque<int> d;
	mstack.push(5); 
	mstack.push(17);
	// std::cout << mstack.top() << std::endl; 
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); //[...] mstack.push(0);

	d.push_back(5);
	d.push_back(17);
	d.push_back(3);
	d.push_back(5);
	d.push_back(737);

	std::deque<int>::const_iterator it = d.begin();
	std::deque<int>::iterator ite = d.end();
	if (it < ite)
		std::cout << "all good\n";

	//using != to compare a const_iterator and an iterator is allowed because the comparison is
	// performed in the direction of constness (i.e., const_iterator is convertible to iterator)

	//however, if it is dropped into fun(std::deque<int>::iterator), there would be a compilation error

	// MutantStack<int>::const_iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite) {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	for (; rit != rite; rit++)
		std::cout << *rit << "\n";
	std::stack<int> s(mstack); 

	std::list<int> lst;
	lst.push_back(5); 
	lst.push_back(17);
	std::cout << lst.back() << std::endl; 
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3); lst.push_back(5); 
	lst.push_back(737); //[...] lst.push(0);
	std::list<int>::iterator it1 = lst.begin();
	std::list<int>::iterator ite1 = lst.end();
	++it1;
	--it1;
	while (it1 != ite1) {
		std::cout << *it1 << std::endl;
		++it1; 
	}
	return 0;
}