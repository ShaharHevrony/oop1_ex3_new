#include "zi.h"
#include <ostream>
#include <cmath>

Zi::Zi(int a, int b):m_real(a), m_imag(b){}

Zi::Zi(const Zi& other):m_real(other.real()), m_imag(other.imag()){}

Zi::~Zi(){}

int Zi::real() const{
    return m_real;
}

int Zi::imag() const{
    return m_imag;
}

int Zi::norm() const{
    return m_real*m_real + m_imag*m_imag;
}

Zi Zi::conj() const{
    return Zi(m_real,-m_imag);
}

bool Zi::dividedBy(const Zi& divisor) const{
    if(Zi(m_real, m_imag) % divisor == 0){
        return true;
    } else {
        return false;
    }
}

Zi operator+(const Zi& z1, const Zi& z2){
    return Zi(z1.real() + z2.real(), z1.imag() + z2.imag());
}

Zi& operator+=(Zi& z1, const Zi& z2) {
    z1 = z1 + z2;
    return z1;
}

Zi operator-(const Zi& z1, const Zi& z2){
    return Zi(z1.real() - z2.real(), z1.imag() - z2.imag());
}

Zi& operator-=(Zi& z1, const Zi& z2){
    z1 = z1 - z2;
    return z1;
}

Zi operator*(const Zi& z1, const Zi& z2){
    int real1 = z1.real();
    int imag1 = z1.imag();
    int real2 = z2.real();
    int imag2 = z2.imag();

    return Zi((real1*real2 - imag1*imag2) , (real1*imag2 + real2*imag1));
}

Zi& operator*=(Zi& z1, const Zi& z2){
    z1 = z1 * z2;
    return z1;
}

Zi operator/(const Zi& z1, const Zi& z2) {
    Zi conj = z2.conj();
    int norm = z2.norm();
    Zi mul = z1 * conj;
    return Zi(round((double)mul.real() / norm), round((double)mul.imag() / norm));
}
    
Zi& operator/=(Zi& z1, const Zi& z2){
    z1 = z1 / z2;
    return z1;
}

Zi operator%(const Zi& z1, const Zi& z2){
    Zi z3 = z1 / z2;
    z3 *= z2;
    return z1 - z3;
}

Zi& operator%=(Zi& z1, const Zi& z2){
    z1 = z1 % z2;
    return z1;
}

Zi operator-(const Zi& z){
    return Zi(-z.real(), -z.imag());
}

bool operator==(const Zi& z1, const Zi& z2){
    return z1.real()==z2.real() && z1.imag()==z2.imag();
}

bool operator!=(const Zi& z1, const Zi& z2){
    return !(z1==z2);
}

std::ostream& operator<<(std::ostream& os, const Zi& z){
    if (z.imag() >= 0) {
        os << z.real() << "+" << z.imag() << "i";
        return os;
    } else {
        os << z.real() << z.imag() << "i";
        return os;
    }
}

Zi& Zi::operator=(const Zi& other){
    if (this == &other) {
        return *this;
    }
    this->m_real = other.real();
    this->m_imag = other.imag();
    return *this;
}