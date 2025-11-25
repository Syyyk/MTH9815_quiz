#include <iostream>
#include <vector>
#include "MaxHeap.hpp"
#include "sort.hpp"

int main() {
	std::cout << "Testing sorting" << std::endl;
	std::vector<int> arr = { 777, 55, 75, 90, 888, 24, 2, 66 };

	radixSort(arr);

	for (int x : arr) std::cout << x << " ";
	std::cout << std::endl << std::endl;
	std::cout << "Testing heap" << std::endl;

	MaxHeap h;
	h.Add(10);
	h.Add(4);
	h.Add(15);
	h.Add(20);
	h.Add(3);

	h.Print();  // 20 15 10 4 3

	std::cout << "Removed: " << h.Remove() << "\n";
	h.Print();  // 15 4 10 3

	return 0;
}
