#include"complex.hpp"

std::ostream & operator<<(std::ostream & os, Complex &c){
    os<<c.real<<"+"<<c.imag<<'i'<<std::endl;
    return os;
}

std::istream & operator>>(std::istream & os, Complex &c){
    os>>c.real>>c.imag;
    return os;
}

Complex Complex:: operator=(const Complex & a) const {
    Complex res;
    res.real = a.real;
    res.imag = a.imag;
    return res;
}

Complex operator+(const Complex & a, const Complex & b){
    Complex res(a.real + b.real, a.imag + b.imag);
    return res;
}

Complex operator-(const Complex & a, const Complex & b){
    Complex res(a.real - b.real, a.imag-b.imag);
    return res;
}

bool operator == (const Complex &a, const Complex & b){
    return (a.real == b.real) && (a.imag == b.imag);
}


bool operator != (const Complex &a, const Complex & b){
    return (a.real != b.real) || (a.imag == b.imag);
}

