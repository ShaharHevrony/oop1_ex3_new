#ifndef OOP1_EX03_NEW_ARRAY_H
#define OOP1_EX03_NEW_ARRAY_H
#include <iosfwd>

#include "zi.h"

class ZiArray {
public:
    //constructor that build array that contain in each index a complex number
    explicit ZiArray(int size = 0, const Zi& value = Zi());

    //constructor that build array that contain in each index a complex number
    ZiArray(const Zi arr[], int size);

    //copy constructor of the complex array
    ZiArray(const ZiArray& other);

    //destructor of the complex array
    ~ZiArray();

    // assignment operator between arrays
    ZiArray& operator=(const ZiArray& other);

    //get the size of the array
    int size() const;

    //check if empty
    bool empty() const;

    //check in the index in the array
    const Zi& operator[](int index) const; //to read

    //check in the index in the array and return the complex number
    Zi& operator[](int index); //to write

private:
	int m_size;

    Zi* m_ziArr;
};

//add between two arrays of complex numbers
ZiArray operator+(const ZiArray& arr1, const ZiArray& arr2);

// put the result of the adding in the first number
ZiArray& operator+=(ZiArray& arr1, const ZiArray& arr2);

//check if the array is even
bool operator==(const ZiArray& arr1, const ZiArray& arr2);

//check if the array are not even
bool operator!=(const ZiArray& arr1, const ZiArray& arr2);

#endif //OOP1_EX03_NEW_ARRAY_H
