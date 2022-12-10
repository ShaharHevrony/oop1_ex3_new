//
// Created by Hevrony on 29/11/2022.
//

#ifndef OOP1_EX03_NEW_VECTOR_H
#define OOP1_EX03_NEW_VECTOR_H
#include "ziArray.h"

class Vector {
public:
    //constructor that build array that contain in each index a complex number
    explicit Vector (int size = 0, const Zi& init = {});

    //constructor that build an array of complex numbers
    Vector (const Zi arr[], int size);

    //copy constructor of the complex array
    Vector (const Vector& other);

    //destructor of the complex array
    ~Vector();

    // assignment operator between arrays
    Vector& operator= (const Vector& other);

    //return the complex number in a certain cell in the array
    const Zi& operator[] (int index) const; //to read

    //return the complex number in a certain cell in the array
    Zi& operator[] (int index); //to write

    //return the size of the vector
    int size() const ;

    //return private variable m_ziarray
    ZiArray ziArray() const;

private:
    ZiArray m_ZiArray;
};

//add between vectors
Vector operator+(const Vector& vector1, Vector& vector2);

//put the result of the adding in the first vector
Vector& operator+=(Vector& vector1, Vector& vector2);

//minus between two vectors
Vector operator-(const Vector& vector1, Vector& vector2);

//put in the minus result in the first vector
Vector& operator-=(Vector& vector1, Vector& vector2);

//multiple between vectors
Vector operator* (const Vector& vector1, const Vector& vector2);

//put in the multiply result in the first vector
Vector& operator*=(Vector& vector1, const Vector& vector2);

//multiply in skalar
Vector operator*(const Vector& vector, const Zi& z);

//put the result of the skalar multiply in the first number
Vector& operator*=(Vector& vector, const Zi& z);

//unary operator
Vector& operator-(Vector& vector);

//check if the vectors are even
bool operator==(const Vector& vector1, const Vector& vector2);

//check if the vectors are not even
bool operator!=(const Vector& vector1, const Vector& vector2);

//print the vectors
std::ostream& operator<<(std::ostream& os, const Vector& vector);

#endif //OOP1_EX03_NEW_VECTOR_H
