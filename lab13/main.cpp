#include"matrix.hpp"
#include<iostream>

using namespace std;

int main(){
    Matrix<int> mat_a(3, 4, 4);
    Matrix<int> mat_b(3, 4, 5);
    mat_a(2, 3) = 23;
    mat_b(2, 3) = 27;

    Matrix<int> mat_c = mat_b + mat_a;
    cout<<mat_a<<endl;
    cout<<mat_b<<endl;
    cout<<mat_c<<endl;

    return 0;
}
