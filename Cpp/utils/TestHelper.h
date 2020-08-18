#ifndef __TESTHELPER_H__
#define __TESTHELPER_H__

#include <iostream>
#include <cassert>
#include <ctime>
#include <chrono> // c++11's standard library

namespace TestHelper {
	/* range [rangeL, rangeR] */
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);

		int* arr = new int[n];
		srand(static_cast<unsigned int>(time(NULL)));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

		return arr;
	}

	int* generateNearlyOrderedArray(int n, int swapTimes) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;

		srand(static_cast<unsigned int>(time(NULL)));
		for (int i = 0; i < swapTimes; i++) {
			int posX = rand() % n;
			int posY = rand() % n;
			std::swap(arr[posX], arr[posY]);
		}

		return arr;
	}

	int* copyIntArray(int* src, int n) {
		int* dest = new int[n];
		std::copy(src, src + n, dest);
		return dest;
	}

	template <typename T>
	void printArray(T* arr, int n) {
		for (int i = 0; i < n; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	template <typename T>
	bool isSorted(T* arr, int n) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}

	template <typename T>
	void testSort(std::string sortName, void(*sort)(T*, int), T* arr, int n) {	
		//clock_t startTime = std::clock();
		//clock_t endTime = std::clock();
		//std::cout << sortName << " : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;

		auto startTime = std::chrono::high_resolution_clock::now();
		sort(arr, n);
		auto endTime = std::chrono::high_resolution_clock::now();
		
		assert(isSorted(arr, n));
		std::cout << sortName << " : " << std::chrono::duration<double>(endTime - startTime).count() << " s" << std::endl;
	}
}

#endif // __TESTHELPER_H__
