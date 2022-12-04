//
// Created by Hevrony on 29/11/2022.
//

#ifndef OOP1_EX03_NEW_VECTOR_H
#define OOP1_EX03_NEW_VECTOR_H
#include "ziArray.h"

class Vector {
public:
    explicit Vector (int size = 0, const Zi& init = {});

    Vector (const Zi arr[], int size);

    Vector (const Vector& other);

    ~Vector();

    Vector& operator=(const Vector& other);

    const Zi& operator[](int index) const; //to read

    Zi& operator[](int index); //to write

    int size() const ;

    ZiArray ziArray() const;

private:
    ZiArray m_ZiArray;
};

Vector operator+(const Vector& vector1, const Vector& vector2);

Vector& operator+=(Vector& vector1, const Vector& vector2);

Vector operator-(const Vector& vector1, const Vector& vector2);

Vector& operator-=(Vector& vector1, const Vector& vector2);

Vector operator*(const Vector& vector1, const Vector& vector2);

Vector& operator*=(Vector& vector1, const Vector& vector2);

Vector operator*(const Vector& vector, const Zi& z);

Vector& operator*=(Vector& vector, const Zi& z);

Vector& operator-(Vector& vector);

bool operator==(const Vector& vector1, const Vector& vector2);

bool operator!=(const Vector& vector1, const Vector& vector2);

std::ostream& operator<<(std::ostream& os, const Vector& vector);

#endif //OOP1_EX03_NEW_VECTOR_H
