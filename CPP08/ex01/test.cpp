#include <set>
#include <iostream>

int main()
{
	std::multiset<int> arr;

	int array[] = {0, 1, 1, 2, 2, 2, 3, 5, 6};
	arr.insert(array, array + 9);

	using iterator = std::multiset<int>::iterator;

	for (iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << "\n";
}

