#include"matrix.hpp"
#include<iostream>
using namespace std;

int main(){

    Matrix<int> mat_a(2, 5, 5);
    
    Matrix<int> mat_b(5, 2, 2);
    Matrix<int> mat_c = mat_a * mat_b;
    mat_c *= mat_c;
    mat_c.info();


    return 0;
}