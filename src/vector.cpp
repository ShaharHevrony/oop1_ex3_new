#include "vector.h"
#include <iostream>

//constructor that build an array of complex numbers
Vector::Vector (int size , const Zi& init): m_ZiArray(size,init){}

//constructor that build an array of complex numbers
Vector::Vector (const Zi arr[], int size): m_ZiArray(arr, size){}

//copy constructor of the complex array
Vector::Vector (const Vector& other): m_ZiArray(other.m_ZiArray){}

//destructor of the complex array
Vector::~Vector (){}

// assignment operator between arrays
Vector& Vector::operator=(const Vector& other){
    this->m_ZiArray = other.m_ZiArray;
    return *this;
}

//return the complex number in a certain cell in the array
const Zi& Vector::operator[](int index) const {
    return m_ZiArray[index];
}

//return the complex number in a certain cell in the array
Zi& Vector::operator[](int index) {
    return m_ZiArray[index];
}

//return the size of the vector
int Vector::size() const {
    return m_ZiArray.size();
}

//return private variable m_ziarray
ZiArray Vector::ziArray() const {
    return m_ZiArray;
}

//add between vectors
Vector operator+(const Vector& vector1, Vector& vector2) {
    //create new vector
    Vector newVector = Vector();
    //if vector1 is bigger then vector2
    if (vector1.size() >= vector2.size()) {
        //the size of the new vector
        newVector = Vector(vector1);
        //add between vector by cells
        for (int index = 0; index < vector2.size(); index++) {
            newVector[index] += vector2[index];
        }
    }
    else {
        //size of the new vector
        newVector = Vector(vector2);
        //add between vector by cells
        for (int index = 0; index < vector1.size(); index++) {
            newVector[index] += vector1[index];
        }
    }
    //return the new vector
    return Vector(newVector);
}

//put the result of the adding in the first vector
Vector& operator+=(Vector& vector1, Vector& vector2){
    vector1 = vector1 + vector2;
    return vector1;
}

//minus between two vectors
Vector operator-(const Vector& vector1, Vector& vector2){
    Vector vector = vector1 + (-vector2);
    //return vector2 to the start
    -vector2;
    return vector;
}

//put in the minus result in the first vector
Vector& operator-=(Vector& vector1, Vector& vector2){
    vector1 = vector1 - vector2;
    return vector1;
}

//multiple between vectors
Vector operator*(const Vector& vector1, const Vector& vector2){
    //creat new vector
    Vector newVector;
    if(vector1.size() >= vector2.size()){
        //update size of the new vector
        newVector = Vector(vector1);
        //multiply ann put in the current number
        for(int index = 0 ; index < vector2.size() ; index++){
            newVector[index] *= vector2[index];
        }
        //if there is 0 left multiply by 0
        for (int index = vector2.size(); index < vector1.size(); index++) {
            newVector[index] *= Zi();
        }
    } else{
        //update size of the new vector
        newVector = Vector(vector2);
        //multiply ann put in the current number
        for(int index = 0 ; index < vector1.size() ; index++){
            newVector[index] *= vector1[index];
        }
        //if there is 0 left multiply by 0
        for (int index = vector1.size(); index < vector2.size(); index++) {
            newVector[index] *= Zi();
        }
    }
    return Vector(newVector);
}

//put in the multiply result in the first vector
Vector& operator*=(Vector& vector1, const Vector& vector2){
    vector1 = vector1 * vector2;
    return vector1;
}

//multiply in skalar
Vector operator*(Vector& vector, const Zi& z){
    for(int index = 0; index < vector.size(); index++){
        vector[index] *= z;
    }
    return vector;
}

//put the result of the skalar multiply in the first number
Vector& operator*=(Vector& vector, const Zi& z){
    vector = vector * z;
    return vector;
}

//unary operator
Vector& operator-(Vector& vector){
    for(int index = 0; index < vector.size(); index++){
        vector[index] = -vector[index];
    }
    return vector;
}

//check if the vectors are even
bool operator==(const Vector& vector1, const Vector& vector2){
    return vector1.ziArray() == vector2.ziArray();
}

//check if the vectors are not even
bool operator!=(const Vector& vector1, const Vector& vector2){
    return !(vector1==vector2);
}

//print the vectors
std::ostream& operator<<(std::ostream& os, const Vector& vector){
    if(vector.ziArray().empty()){
        return os;
    }
    for (int index = 0; index < vector.size() - 1; index++){
        os << vector[index] << std::string(1, ' ');
    }
    os << vector[vector.size() - 1];
    return os;
}