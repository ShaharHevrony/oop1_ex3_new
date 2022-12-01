#include "array.h"

Array::Array(int size, const Zi& value):m_zi(value), m_size(size){}

Array::Array(const Zi arr[], int size){}

Array::Array(const Array& old){}

int Array::size() const{
	return m_size;
}

bool Array::empty() const{
	if (m_size == 0) {
		return true;
	} else {
		return false;
	}
}

Array operator+(const Array& arr1, const Array& arr2){
	Zi arr[arr1.size() + arr2.size()];
}

Array operator+=(Array& arr1, const Array& arr2) {}

const Zi& Array::operator[](int index) const {} //to read

Zi& Array::operator[](int index) {} //to write

bool operator==(const Array& arr1, const Array& arr2) {}

bool operator!=(const Array& arr1, const Array& arr2) {}
