#include "vector.h"
#include <iostream>

// Created by Hevrony on 29/11/2022.
Vector::Vector (int size , const Zi& init): m_ZiArray(size,init){}

Vector::Vector (const Zi arr[], int size): m_ZiArray(arr, size){}

Vector::Vector (const Vector& other): m_ZiArray(other.m_ZiArray){}

Vector::~Vector (){}

Vector& Vector::operator=(const Vector& other){
    this->m_ZiArray = other.m_ZiArray;
    return *this;
}

const Zi& Vector::operator[](int index) const {
    return m_ZiArray[index];
}

Zi& Vector::operator[](int index) {
    return m_ZiArray[index];
}

int Vector::size() const {
    return m_ZiArray.size();
}

ZiArray Vector::ziArray() const {
    return m_ZiArray;
}

Vector operator+(const Vector& vector1, Vector& vector2) {
    Vector newVector = Vector();
    if (vector1.size() >= vector2.size()) {
        newVector = Vector(vector1);
        for (int index = 0; index < vector2.size(); index++) {
            newVector[index] += vector2[index];
        }
    }
    else {
        newVector = Vector(vector2);
        for (int index = 0; index < vector1.size(); index++) {
            newVector[index] += vector1[index];
        }
    }
    return Vector(newVector);
}

Vector& operator+=(Vector& vector1, Vector& vector2){
    vector1 = vector1 + vector2;
    return vector1;
}

Vector operator-(const Vector& vector1, Vector& vector2){
    Vector vector = vector1 + (-vector2);
    -vector2;
    return vector;
}

Vector& operator-=(Vector& vector1, Vector& vector2){
    vector1 = vector1 - vector2;
    return vector1;
}

Vector operator*(const Vector& vector1, const Vector& vector2){
    Vector newVector;
    if(vector1.size() >= vector2.size()){
        newVector = Vector(vector1);
        for(int index = 0 ; index < vector2.size() ; index++){
            newVector[index] *= vector2[index];
        }
        for (int index = vector2.size(); index < vector1.size(); index++) {
            newVector[index] *= Zi();
        }
    } else{
        newVector = Vector(vector2);
        for(int index = 0 ; index < vector1.size() ; index++){
            newVector[index] *= vector1[index];
        }
        for (int index = vector1.size(); index < vector2.size(); index++) {
            newVector[index] *= Zi();
        }
    }
    return Vector(newVector);
}

Vector& operator*=(Vector& vector1, const Vector& vector2){
    vector1 = vector1 * vector2;
    return vector1;
}

Vector operator*(Vector& vector, const Zi& z){
    for(int index = 0; index < vector.size(); index++){
        vector[index] *= z;
    }
    return vector;
}

Vector& operator*=(Vector& vector, const Zi& z){
    vector = vector * z;
    return vector;
}

Vector& operator-(Vector& vector){
    for(int index = 0; index < vector.size(); index++){
        vector[index] = -vector[index];
    }
    return vector;
}

bool operator==(const Vector& vector1, const Vector& vector2){
    return vector1.ziArray() == vector2.ziArray();
}

bool operator!=(const Vector& vector1, const Vector& vector2){
    return !(vector1==vector2);
}

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