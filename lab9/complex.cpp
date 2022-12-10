#include"complex.hpp"
#include<iostream>



Complex Complex::add(const Complex & b){
    Complex res;
    res.setReal(this->getReal() + b.getReal());
    res.setImag(this->getImag() + b.getImag());
    return res;
}

Complex Complex::subtract(const Complex & b){
    Complex res;
    res.setReal(this->getReal() - b.getReal());
    res.setImag(this->getImag() - b.getImag());
    return res;
}

void Complex::display() const{
    std::cout<<a<<"+"<<b<<"i"<<std::endl;
}