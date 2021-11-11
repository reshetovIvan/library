#pragma once

template<typename T>
class Array {
private:
	T* array = new T[0];
	int size=0;

public:
	Array(T a1, T a2, T a3, T a4) {
		delete[] array;
		array = new int[4];
		array[0] = a1;
		array[1] = a2;
		array[2] = a3;
		array[3] = a4;
		size = 4;
	}
	void showArray() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";

		}
		cout << endl;
	}
	int getSize() {
		return this->size;
	}

	bool isEmpty() {
		if (size == 0) return true;
		else return false;
	}

	void removeAll() {
		delete[]array;
		size = 0;
	}

	T getAt(int i) {
		return array[i];
	}

	void setAt(int i, T element) {
		if (i <= size - 1) {
			array[i] = element;
		}
	}

	T& operator [] (int i) {
		return array[i];
	}

	void add(T element) {
		T* buf = new T[size + 1];
		for (int i = 0; i < size; i++) {
			buf[i] = array[i];
		}
		buf[size++] = element;
		delete[] array;
		array = buf;
	}

	void append(Array array2) {
		int size2= array2.getSize()
		T* buf = new T[size + size2];
		for (int i = 0; i < size; i++) {
			buf[i] = array[i];
		}
		for (int i = size; i < size + size2; i++) {
			buf[i] = array2[i - size];
		}
		delete[] array;
		array = buf;
		size += size2;
	}

	void operator = (Array array2) {
		delete[]array;
		int size2 = array2.getSize();
		T* array = new T[size2];
		for (int i = 0; i < size2; i++) {
			array[i] = array2[i];
		}
		size = size2;
	}

	T** setData() {
		return &array;
	}

	void insertAt(int n, T element) {
		T * buf = new T[size + 1];
		for (int i = 0; i < n; i++) {
			buf[i] = array[i];
		}
		buf[n] = element;
		for (int i = n+1; i < size + 1; i++) {
			buf[i] = array[i-1];
		}
		delete[] array;
		array = buf;
		size += 1
	}

	void removeAt(int n, T element) {
		T* buf = new T[size - 1];
		for (int i = 0; i < n; i++) {
			buf[i] = array[i];
		}
		for (int i = n + 1; i < size + 1; i++) {
			buf[i-1] = array[i];
		}
		delete[] array;
		array = buf;
		size -= 1
	}
};