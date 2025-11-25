#include <vector>
#include <iostream>

class MaxHeap {
private:
	std::vector<int> data;

	void bubbleUp(int index) {
		while (index > 0) {
			int parent = (index - 1) / 2;

			if (data[index] <= data[parent]) {
				break;
			}

			std::swap(data[index], data[parent]);
			index = parent;
		}
	}

	void bubbleDown(int index) {
		int n = data.size();

		while (true) {
			int left = index * 2 + 1;
			int right = index * 2 + 2;
			int largest = index;

			if (left < n && data[left] > data[largest]) {
				largest = left;
			}
			if (right < n && data[right] > data[largest]) {
				largest = right;
			}

			if (largest == index) {
				break;  // heap property satisfied
			}

			std::swap(data[index], data[largest]);
			index = largest;
		}
	}

public:
	MaxHeap() = default;

	void Add(int value) {
		data.push_back(value);
		bubbleUp(data.size() - 1);
	}

	// Remove and return the maximum element
	int Remove() {
		if (data.empty()) {
			throw std::out_of_range("Heap is empty");
		}

		int maxVal = data[0];

		// Move last element to root
		data[0] = data.back();
		data.pop_back();

		// Restore heap property if not empty
		if (!data.empty()) {
			bubbleDown(0);
		}

		return maxVal;
	}

	void Print() const {
		for (int x : data) {
			std::cout << x << " ";
		}
		std::cout << "\n";
	}
};
