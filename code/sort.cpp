#include "sort.hpp"

// since the elements are all integers, can use a radix sort which is quicker

int getMax(const std::vector<int>& arr) {
	int mx = arr[0];
	for (int x : arr) mx = std::max(mx, x);
	return mx;
}

// Counting sort by digit (exp = 1, 10, 100, ...)
// Suppose at most 10 digits (because it's int)
// In-place operation
void countingSort(std::vector<int>& arr, int exp) {
	int n = arr.size();
	std::vector<int> output(n);
	int count[10] = { 0 };

	// Count occurrences of each digit
	for (int x : arr) {
		int digit = (x / exp) % 10;
		count[digit]++;
	}

	// Prefix sum
	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	// Build stable output array
	for (int i = n - 1; i >= 0; --i) {
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	arr = output;
}

void radixSort(std::vector<int>& arr) {
	int maxVal = getMax(arr);

	for (int exp = 1; maxVal / exp > 0; exp *= 10)
		countingSort(arr, exp);
}
