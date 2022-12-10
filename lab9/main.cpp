#include"complex.hpp"
#include<iostream>


int main(){
    Complex a(4, 6);
    Complex b(5.0f, 23.6f);
    a.display();
    b.display();
    Complex c = a.add(b);
    c.display();

    return 0;
}