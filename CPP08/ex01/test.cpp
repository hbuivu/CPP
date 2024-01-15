#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::pair<int, int> findClosestNumbers(const std::vector<int>& sequence) {
    if (sequence.size() < 2) {
        throw std::invalid_argument("At least two numbers are required.");
    }

    auto minIt = std::min_element(sequence.begin(), sequence.end());
    auto maxIt = std::max_element(sequence.begin(), sequence.end());

    return std::make_pair(*minIt, *maxIt);
}

int main() {
    try {
		int array_data[] = {1, 3, 5, 6, 7, 9};
        std::vector<int> numbers(array_data, array_data + sizeof(array_data) / sizeof(array_data[0]));
        std::pair<int, int> closestNumbers = findClosestNumbers(numbers);

        std::cout << "Closest numbers: " << closestNumbers.first << " and " << closestNumbers.second << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}