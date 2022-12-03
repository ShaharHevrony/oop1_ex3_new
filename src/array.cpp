#include "array.h"

Array::Array(int size, const Zi& value):m_size(size){
	Zi* m_arr = new Zi[m_size];
	for (int count = 0; count < m_size; count++){
		m_arr[count] = value;
	}
}

Array::Array(const Zi arr[], int size):m_size(size){
	Zi* m_arr = new Zi[m_size];
	for (int count = 0; count < m_size; count++) {
		m_arr[count] = arr[count];
	}
}

Array::Array(const Array& old):m_size(old.m_size){
	Zi* m_arr = new Zi[m_size];
	for (int count = 0; count < m_size; count++) {
		m_arr[count] = old[count];
	}
}

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

Array operator+=(Array& arr1, const Array& arr2){}

const Zi& Array::operator[](int index) const {} //to read

Zi& Array::operator[](int index) {} //to write

bool operator==(const Array& arr1, const Array& arr2) {}

bool operator!=(const Array& arr1, const Array& arr2) {}
