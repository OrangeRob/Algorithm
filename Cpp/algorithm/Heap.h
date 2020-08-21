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
		assert(k > 0);

		return (k - 1) / 2;
	}

	int leftChild(int k) {
		assert(k * 2 + 1 < count);

		return k * 2 + 1;
	}

	int rightChild(int k) {
		assert(k * 2 + 2 < count);

		return k * 2 + 2;
	}

	T get(int index) const {
		assert(index < count);

		return data[index];
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

public:
	MinHeap(int capacity) {
		data = new T[capacity];
		count = 0;
		this->capacity = capacity;
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

	T extractMin() {
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
		assert(k > 0);
		return (k - 1) / 2;
	}

	int leftChild(int k) {
		assert(k * 2 + 1 < count);
		return k * 2 + 1;
	}

	int rightChid(int k) {
		assert(k * 2 + 2 < count);
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

	T extractMax() {
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

#endif // __HEAP_H__