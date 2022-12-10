#include "ziArray.h"

//constructor that build array that contain in each index a complex number
ZiArray::ZiArray(int size, const Zi& value): m_size(size){
    m_ziArr = new Zi[m_size];
    for (int count = 0; count < m_size; count++){
        m_ziArr[count] = value;
    }
}

//constructor that build array that contain in each index a complex number
ZiArray::ZiArray(const Zi arr[], int size): m_size(size){
    m_ziArr = new Zi[m_size];
    for (int count = 0; count < m_size; count++) {
        m_ziArr[count] = arr[count];
	}
}

//copy constructor of the complex array
ZiArray::ZiArray(const ZiArray& other):m_size(other.m_size){
    m_ziArr = new Zi[m_size];
	for (int count = 0; count < m_size; count++) {
        m_ziArr[count] = other[count];
	}
}

//destructor of the complex array
ZiArray::~ZiArray(){
    delete [] m_ziArr;
}

// assignment operator between arrays
ZiArray& ZiArray::operator=(const ZiArray& other){
    if(this != &other){
        delete[] m_ziArr;
        m_ziArr = new Zi[other.m_size];
        m_size = other.m_size;
        for (int count = 0; count < m_size; count++) {
            m_ziArr[count] = other[count];
        }
    }
    return *this;
}

//get the size of the array
int ZiArray::size() const{
	return m_size;
}

//check if empty
bool ZiArray::empty() const{
	if (m_size == 0) {
		return true;
	} else {
		return false;
	}
}

//check in the index in the array
const Zi& ZiArray::operator[](int index) const {
    return m_ziArr[index];
}

//check in the index in the array and return the complex number
Zi& ZiArray::operator[](int index) {
    return m_ziArr[index];
}

//add between two arrays of complex numbers
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

// put the result of the adding in the first number
ZiArray& operator+=(ZiArray& arr1, const ZiArray& arr2){
    arr1 = arr1 + arr2;
    return arr1;
}

//check if the array is even
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

//check if the array are not even
bool operator!=(const ZiArray& arr1, const ZiArray& arr2) {
    return !(arr1==arr2);
}
