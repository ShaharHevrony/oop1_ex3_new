#ifndef OOP1_EX03_NEW_ARRAY_H
#define OOP1_EX03_NEW_ARRAY_H
#include <iosfwd>

#include "zi.h"

class Array {
public:
	Array(int size = 0, const Zi& value = Zi());

	Array(const Zi arr[], int size);

	Array(const Array& old);

	int size() const;

	bool empty() const;

	const Zi& operator[](int index) const; //to read
	Zi& operator[](int index); //to write

private:
	Zi *m_zi;
	int m_size;
};

Array operator+(const Array& arr1, const Array& arr2);

Array operator+=(Array& arr1, const Array& arr2);


bool operator==(const Array& arr1, const Array& arr2);

bool operator!=(const Array& arr1, const Array& arr2);

#endif //OOP1_EX03_NEW_ARRAY_H
