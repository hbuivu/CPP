#include <sstream>
#include <fstream>
#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>

int Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

std::deque<int> genJacobIndex(size_t size)
{
	std::deque<int> container;
	int	prevJacobNum = 1;
	int	jacobNum = 3;
	int i = 3;
	while (size > jacobNum)
	{
		jacobNum = Jacobsthal(i);
		container.push_back(jacobNum);
		for (int index = jacobNum - 1; index > prevJacobNum; index--)
			container.push_back(index);
		i++;
		prevJacobNum = jacobNum;
	}
	return (container);
}

int main(int argc, char **argv)
{
	std::deque<int> deck;
	std::deque<std::pair<int, int> > pairs;

	int i = 1;
	// while (argv[i])
	// {
	// 	std::istringstream ss(argv[i]);
	// 	int num;
	// 	ss >> num;
	// 	if (ss.fail())
	// 		std::cout << "not a number";
	// 	else if (ss.get() != EOF)
	// 		std::cout << "there's still stuff after the number";
	// 	deck.push_back(num);
	// 	i++;
	// }

	// for (int i = 0; i < deck.size(); i += 2)
	// 	pairs.push_back(std::make_pair(deck[i], deck[i + 1]));
	// std::cout << "Unsorted: \n";
	// for (int i = 0; i < pairs.size(); i++)
	// 	std::cout << "(" << pairs[i].first << "," << pairs[i].second << ")\n";
	// for (int i = 0; i < pairs.size(); i++)
	// 	if (pairs[i].first < pairs[i].second)
	// 		std::swap(pairs[i].first, pairs[i].second);
	// std::sort(pairs.begin(), pairs.end());
	// std::cout << "Sorted: \n";
	// for (int i = 0; i < pairs.size(); i++)
	// 	std::cout << "(" << pairs[i].first << "," << pairs[i].second << ")\n";

	std::deque<int> jacobSeq = genJacobIndex(23);
	for (std::deque<int>::iterator it = jacobSeq.begin(); it != jacobSeq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::deque<int>::iterator it = jacobSeq.begin();
	std::deque<int>::iterator oldit = it;
	std::cout << "before advancing 2: " << *it << "\n";
	std::advance(it, 2);
	std::cout << "after advancing 2: " << *it << "\n";

	std::cout << std::distance(oldit, it) << "\n";
}
