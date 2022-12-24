#include"matrix.hpp"
#include<iostream>
using namespace std;

int main(){
    Matrix<int> mat_a = Matrix<int>::readMat("./mat.txt");
    mat_a.printMat();
    Matrix<int> mat_b = mat_a.submatrix(1, 4, 1, 4);
    mat_b.printMat();
    mat_b.adjust_ROI(1, 4, 1, 5);
    mat_b.printMat();
    mat_b[0][1] = 34232;
    cout<<mat_b<<std::endl;
    return 0;
}