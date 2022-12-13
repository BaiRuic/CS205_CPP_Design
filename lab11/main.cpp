// #include"matrix.hpp"
#include"matrix_1.hpp"
#include<iostream>

using namespace std;

void test(){
    size_t nums = 34;
    std::shared_ptr<float[]> temp_d = nullptr;
    temp_d = std::make_unique<float[]>(nums);

    for (int i =0; i< nums; i++){
        std::cout << temp_d[i] << ' ';
    }
    cout<<endl;
}

int main(){

    Matrix a(3, 4, 0.5f);
    cout<<'a'<<' '<<a<<endl;
    Matrix b(3, 4, 3.0f);
    cout<<'b'<<' '<<b<<endl;
    a = a + b;
    cout<<'a'<<' '<<a<<endl;
    Matrix c = a + b;
    
    Matrix d = a * 2.0f;
    
    Matrix e;
    e = a; // 赋值构造

    Matrix f(b); // 拷贝构造
    Matrix g = b;

    
    cout<<'b'<<' '<<b<<endl;
    cout<<'c'<<' '<<c<<endl;
    cout<<'d'<<' '<<d<<endl;
    cout<<'e'<<' '<<e<<endl;
    cout<<'f'<<' '<<f<<endl;
    cout<<'g'<<' '<<g<<endl;
    
    return 0;
}