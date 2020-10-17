#ifndef __HEAP_H__
#define __HEAP_H__

#include <cassert>
#include <iomanip>

/** MinHeap **/
template <typename T>
class MinHeap {
private:
	T* data;
	int count;
	int capacity;

	int parent(int k) {
		return (k - 1) / 2;
	}

	int leftChild(int k) {
		return k * 2 + 1;
	}

	int rightChild(int k) {
		return k * 2 + 2;
	}

	void shiftUp(int k) {
		/* index 0 is root node */
		while (k > 0 && data[parent(k)] > data[k]) {
			std::swap(data[parent(k)], data[k]);
			k = parent(k);
		}
	}

	void shiftDown(int k) {
		while (leftChild(k) < count) {
			int j = leftChild(k);
			if (j + 1 < count && data[j] > data[j + 1])
				j++;

			if (data[k] <= data[j])
				break;

			std::swap(data[k], data[j]);
			k = j;
		}
	}

	void heapify() {
		for (int i = parent(count - 1); i >= 0; i--)
			shiftDown(i);
	}

	T get(int index) const {
		assert(index < count);

		return data[index];
	}

public:
	MinHeap(int capacity) {
		data = new T[capacity];
		count = 0;
		this->capacity = capacity;
	}

	MinHeap(T* arr, int n) {
		data = new T[n];
		count = n;
		this->capacity = n;

		for (int i = 0; i < n; i++)
			data[i] = arr[i];

		heapify();
	}

	~MinHeap() {
		delete[] data;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(T e) {
		assert(count < capacity);

		data[count] = e;
		count++;
		shiftUp(count - 1);
	}

	T extract() {
		assert(count > 0);

		T ret = data[0];
		data[0] = data[--count];
		shiftDown(0);
		return ret;
	}

	friend std::ostream& operator<<(std::ostream& os, const MinHeap<T>& obj) {
		int size = obj.count;
		os << "index : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << i << " ";
		}
		os << std::endl;

		os << "data  : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << obj.get(i) << " ";
		}
		os << std::endl;
		return os;
	}
};

/** MaxHeap **/
template <typename T>
class MaxHeap {
private:
	T* data;
	int count;
	int capacity;

	int parent(int k) {
		return (k - 1) / 2;
	}

	int leftChild(int k) {
		return k * 2 + 1;
	}

	int rightChid(int k) {
		return k * 2 + 2;
	}
 
	void shiftUp(int k) {
		/* index 0 is root node */
		while (k > 0 && data[parent(k)] < data[k]) {
			std::swap(data[parent(k)], data[k]);
			k = parent(k);
		}
	}

	void shiftDown(int k) {
		while (leftChild(k) < count) {
			int j = leftChild(k); // j : swap target
			if (j + 1 < count && data[j + 1] > data[j])
				j++;	// right Child

			if (data[k] >= data[j])
				break;

			std::swap(data[k], data[j]);
			k = j;
		}
	}

	/* k is the last node */
	void heapify() {
		for (int i = parent(count - 1); i >= 0; i--)
			shiftDown(i);
	}

	T get(int index) const {
		assert(index < count);
		return data[index];
	}

public:
	MaxHeap(int capacity) {
		data = new T[capacity];
		count = 0;
		this->capacity = capacity;
	}

	MaxHeap(T arr[], int n) {
		data = new T[n];
		count = n;
		this->capacity = n;
		for (int i = 0; i < n; i++)
			data[i] = arr[i];

		heapify();
	}

	~MaxHeap() {
		delete[] data;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(T e) {
		// TODO: relloc ...
		assert(count < capacity);

		data[count] = e;
		count++;
		shiftUp(count -1);
	}

	T extract() {
		assert(count > 0);

		T ret = data[0];
		//std::swap(data[0], data[count - 1]);
		data[0] = data[count - 1];
		count--;

		shiftDown(0);
		return ret;

	}

	friend std::ostream& operator<<(std::ostream& os, const MaxHeap<T>& obj) {
		int size = obj.count;
		os << "index : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << i << " ";
		}
		os << std::endl;

		os << "data  : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << obj.get(i) << " ";
		}
		os << std::endl;
		return os;
	}
};

/** IndexMaxHeap */
template <typename T>
class IndexMaxHeap {
private:
	T* data;
	int* indexes;
	int* reverse;
	int count;
	int capacity;

	int parent(int k) {
		return (k - 1) / 2;
	}

	int leftChild(int k) {
		return 2 * k + 1;
	}

	int rightChild(int k) {
		return 2 * k + 2;
	}

	void shiftUp(int k) {
		while (k > 0 && data[indexes[parent(k)]] < data[indexes[k]]) {
			std::swap(indexes[parent(k)], indexes[k]);
			reverse[indexes[parent(k)]] = parent(k);
			reverse[indexes[k]] = k;

			k = parent(k);
		}
	}

	void shiftDown(int k) {
		while (leftChild(k) < count) {
			int j = leftChild(k);
			if (j + 1 < count && data[indexes[j + 1]] > data[indexes[j]])
				j++;

			if (data[indexes[k]] >= data[indexes[j]])
				break;

			std::swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;

			k = j;
		}
	}

public:
	IndexMaxHeap(int capacity) {
		data = new T[capacity];
		indexes = new int[capacity];
		reverse = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			data[i] = -1;
			indexes[i] = -1;
			reverse[i] = -1;
		}

		count = 0;
		this->capacity = capacity;
	}

	~IndexMaxHeap() {
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(int i, T e) {
		assert(count < capacity);
		assert(i < capacity);

		data[i] = e;
		indexes[count] = i;
		reverse[i] = count;
		count++;

		shiftUp(count - 1);
	}
	
	T extract() {
		assert(count > 0);
		T ret = data[indexes[0]];

		std::swap(indexes[0], indexes[count - 1]);
		reverse[indexes[0]] = 0;
		reverse[indexes[count - 1]] = -1;

		count--;

		shiftDown(0);
		return ret;
	}

	int extractIndex() {
		assert(count > 0);
		int ret = indexes[0];

		std::swap(indexes[0], indexes[count - 1]);
		reverse[indexes[0]] = 0;
		reverse[indexes[count - 1]] = -1;

		count--;
		shiftDown(0);
		return ret;
	}

	bool contain(int i) {
		assert(i < capacity);
		return reverse[i] != -1;
	}

	T get(int i) {
		assert(contain(i));
		return data[i];
	}

	void change(int i, T e) {
		assert(contain(i));
		data[i] = e;

		//for (int j = 0; j < count; j++) {
		//	if (indexes[j] == i) {
		//		shiftUp(j);
		//		shiftDown(j);
		//		return;
		//	}
		//}

		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);

	}

	friend std::ostream& operator<<(std::ostream& os, const IndexMaxHeap<T>& obj) {
		int size = obj.capacity;
		os << "   -    : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << i << " ";
		}
		os << std::endl;

		os << "indexes : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << obj.indexes[i] << " ";
		}
		os << std::endl;

		os << "data    : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << obj.data[i] << " ";
		}
		os << std::endl;

		os << "reserve : ";
		for (int i = 0; i < size; i++) {
			os << std::setw(4) << obj.reverse[i] << " ";
		}
		os << std::endl;
		return os;
	}

};

/** =========== sort ============== **/

/* MaxHeap without heapify */
template <typename T>
void heapSort_1(T* arr, int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxHeap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extract();
	}
}

/* MaxHeap with heapify */
template <typename T>
void heapSort_2(T* arr, int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extract();
	}
}

template <typename T>
void __shiftDown(T* arr, int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1; // j : swap target
		if (j + 1 < n && arr[j + 1] > arr[j])
			j++; // right Child

		if (arr[k] >= arr[j])
			break;

		std::swap(arr[k], arr[j]);
		k = j;
	}
}

/* Maxheap without malloc space */
template <typename T>
void heapSort_3(T* arr, int n) {
	/* hepify */
	for(int i = (n - 1 - 1) / 2; i >= 0; i--)
		__shiftDown(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}

}

#endif // __HEAP_H__