//
// Created by Hevrony on 29/11/2022.
//

#ifndef UNTITLED_ZI_H
#define UNTITLED_ZI_H
#include <iosfwd>

class Zi{
public:
    //constructor of complex number
    Zi(int a=0, int b=0);

    //copy constructor of complex number
    Zi(const Zi& other);

    //destructor of a complex number
    ~Zi();

    //get real number
    int real() const;

    //get image number
    int imag() const;

    //get the norm of the complex number
    int norm() const;

    //get the conj of the complex number
    Zi conj() const;

    //divided by a certain number
    bool dividedBy(const Zi& divisor) const;

    //adding between the complex numbers
    Zi& operator=(const Zi& other);

private:
    int m_real;

    int m_imag;
};

//adding between the complex numbers
Zi operator+(const Zi& z1, const Zi& z2);

//put the adding in a third number
Zi& operator+=(Zi& z1, const Zi& z2);

//minus between two complex numbers
Zi operator-(const Zi& z1, const Zi& z2);

//put the minus in a third number
Zi& operator-=(Zi& z1, const Zi& z2);

//calculate multiply between two complex numbers
Zi operator*(const Zi& z1, const Zi& z2);

// put the multiply result in a third number
Zi& operator*=(Zi& z1, const Zi& z2);

//divided by two complex numbers
Zi operator/(const Zi& z1, const Zi& z2);

//put the divided result in a third number
Zi& operator/=(Zi& z1, const Zi& z2);

// calculate the modulo of the complex number
Zi operator%(const Zi& z1, const Zi& z2);

//put the modulo result in a third number
Zi& operator%=(Zi& z1, const Zi& z2);

//unary minus
Zi operator-(const Zi& z);

// check if the complex numbers are even
bool operator==(const Zi& z1, const Zi& z2);

// check if the complex numbers are not even
bool operator!=(const Zi& z1, const Zi& z2);

//print the complex number
std::ostream& operator<<(std::ostream& os, const Zi& z);

#endif //UNTITLED_ZI_H
