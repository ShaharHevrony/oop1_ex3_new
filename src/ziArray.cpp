#include "ziArray.h"

ZiArray::ZiArray(int size, const Zi& value): m_size(size){
	m_ziArr = new Zi[m_size];
	for (int count = 0; count < m_size; count++){
        m_ziArr[count] = value;
	}
}

ZiArray::ZiArray(const Zi arr[], int size): m_size(size){
    m_ziArr = new Zi[m_size];
    for (int count = 0; count < m_size; count++) {
        m_ziArr[count] = arr[count];
	}
}

ZiArray::ZiArray(const ZiArray& other): m_size(other.m_size){
    m_ziArr = new Zi[m_size];
	for (int count = 0; count < m_size; count++) {
        m_ziArr[count] = other[count];
	}
}

ZiArray::~ZiArray() {
    delete [] m_ziArr;
}

ZiArray& ZiArray::operator=(const ZiArray& other){
    if(this != &other){
        Zi* newArray = new Zi[other.m_size];
        for (int count = 0; count < other.m_size; count++) {
            newArray[count] = other[count];
        }
        delete[] m_ziArr;
        m_ziArr = newArray;
        m_size = other.m_size;
    }
}

int ZiArray::size() const{
	return m_size;
}

bool ZiArray::empty() const{
	if (m_size == 0) {
		return true;
	} else {
		return false;
	}
}

const Zi& ZiArray::operator[](int index) const {
    return m_ziArr[index];
}

Zi& ZiArray::operator[](int index) {
    return m_ziArr[index];
}

ZiArray operator+(const ZiArray& arr1, const ZiArray& arr2){
    ZiArray* array = new ZiArray(arr1.size()+arr2.size(), Zi());
    ZiArray temp = *array;

    for (int count = 0; count < arr1.size(); count++){
        temp[count] = arr1[count];
    }
    for (int count = arr1.size(); count < arr1.size()+arr2.size(); count++){
        temp[count] = arr2[count];
    }
    return temp;
}

ZiArray& operator+=(ZiArray& arr1, const ZiArray& arr2){
    arr1 = arr1 + arr2;
    return arr1;
}

bool operator==(const ZiArray& arr1, const ZiArray& arr2) {
    if(arr1.empty() || arr2.empty()){
        return true;
    } else if (arr1.size() != arr2.size()){
        return false;
    }
    for (int count = 0; count < arr1.size(); count++){
        if(arr1[count] != arr2[count]){
            return false;
        }
    }
    return true;
}

bool operator!=(const ZiArray& arr1, const ZiArray& arr2) {
    return !(arr1==arr2);
}
