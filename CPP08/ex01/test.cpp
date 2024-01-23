#include <set>
#include <vector>
#include <iostream>

int main()
{
	// std::multiset<int> arr;
	std::vector<int> arr;

	// int array[] = {0, 1, 1, 2, 2, 2, 3, 5, 6};
	int array[] = {0, 1, 7, 2, 10, 2, 8, 5, 6};
	arr.insert(arr.end(), array, array + 9);

	// using iterator = std::multiset<int>::iterator;
	using iterator = std::vector<int>::iterator;

	std::sort(arr.begin(), arr.end());
	for (iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << "\n";
		
}

