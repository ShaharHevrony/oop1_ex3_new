//
// Created by Hevrony on 29/11/2022.
//

#ifndef UNTITLED_ZI_H
#define UNTITLED_ZI_H
#include <iosfwd>

class Zi{
public:
    Zi(int a=0, int b=0);

    Zi(const Zi* other);

    ~Zi(); //FIXME:

    int real() const;

    int imag() const;

    int norm() const;

    Zi conj() const;

    bool dividedBy(const Zi& divisor) const;

    Zi operator=(const Zi& other);

private:
    int m_real;

    int m_imag;
};

Zi operator+(const Zi& z1, const Zi& z2);

Zi& operator+=(Zi& z1, const Zi& z2);

Zi operator-(const Zi& z1, const Zi& z2);

Zi& operator-=(Zi& z1, const Zi& z2);

Zi operator*(const Zi& z1, const Zi& z2);

Zi& operator*=(Zi& z1, const Zi& z2);

Zi operator/(const Zi& z1, const Zi& z2);

Zi& operator/=(Zi& z1, const Zi& z2);

Zi operator%(const Zi& z1, const Zi& z2);

Zi& operator%=(Zi& z1, const Zi& z2);

Zi operator-(const Zi& z);

bool operator==(const Zi& z1, const Zi& z2);

bool operator!=(const Zi& z1, const Zi& z2);

std::ostream& operator<<(std::ostream& os, const Zi& z);

#endif //UNTITLED_ZI_H
