#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include<iostream>

class Complex{
    private:
    float real;
    float imag;
    
    public:
    Complex(float r=0, float i=0): real(r), imag(i) {}
    Complex(float r): real(r){}

    float getReal() const{
        return real;
    }
    float getImag() const{
        return imag;
    }
    void setReal(float real){
        this->real = real;
    }
    void setImag(float imag){
        this->imag = imag;
    }

    // 只能写作 成员函数
    Complex operator= (const Complex & ) const;
    
    // 类外函数，友元
    friend 
    std::ostream & operator << (std::ostream & os, Complex & c); 
    friend
    std::istream & operator >>(std::istream & os, Complex &c);

    friend
    Complex operator+ (const Complex &, const Complex &);

    friend
    Complex operator-(const Complex &, const Complex &);

    friend
    bool operator==(const Complex &, const Complex &);

    friend
    bool operator !=(const Complex &, const Complex &);   
};



#endif