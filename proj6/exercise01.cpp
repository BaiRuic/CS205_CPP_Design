#include<iostream>

using std::cout;
using std::endl;

void swapByVal(int num1, int num2){
    int num = num2;
    num2 = num1;
    num2 = num;
}

void swapByPoint(int * num1, int * num2){
    int num = *num2;
    *num2 = * num1;
    *num1 = num;
}

void swapByrefer(int & num1, int & num2){
    int num = num2;
    num2 = num1;
    num1 = num;
}


void test(int a, int b){

}

int main(){
    int a = 1;
    int b = 2;
    cout<<"a:"<<a<<",b:"<<b<<endl;

    cout<<"swapByPoint"<<endl;
    swapByPoint(&a, &b);
    cout<<"a:"<<a<<",b:"<<b<<endl;

    cout<<"swapByVal"<<endl;
    swapByVal(a, b);
    cout<<"a:"<<a<<",b:"<<b<<endl;
    
    cout<<"swapByrefer"<<endl;
    swapByrefer(a, b);
    cout<<"a:"<<a<<",b:"<<b<<endl;

    return 0;   
}
