#ifndef OOP1_EX03_NEW_ARRAY_H
#define OOP1_EX03_NEW_ARRAY_H
#include <iosfwd>

#include "zi.h"

class ZiArray {
public:
	explicit ZiArray(int size = 0, const Zi& value = Zi());

	ZiArray(const Zi arr[], int size);

	ZiArray(const ZiArray& other);

    ~ZiArray();

    ZiArray& operator=(const ZiArray& other);

	int size() const;

	bool empty() const;

	const Zi& operator[](int index) const; //to read

	Zi& operator[](int index); //to write

private:
	int m_size;

    Zi* m_ziArr;
};

ZiArray operator+(const ZiArray& arr1, const ZiArray& arr2);

ZiArray& operator+=(ZiArray& arr1, const ZiArray& arr2);

bool operator==(const ZiArray& arr1, const ZiArray& arr2);

bool operator!=(const ZiArray& arr1, const ZiArray& arr2);

#endif //OOP1_EX03_NEW_ARRAY_H
