#include<iostream>
using namespace std;


int main(){
    int p2[5];

    int * p = (int *) malloc(5 * sizeof(int));
    // 打印 数组首地址,因为该数组是动态申请的，所以 p 和 &p不一样
    cout<<"动态申请的内存地址" <<p<<" "<< &p <<endl;
    cout<<"非动态申请的内存地址" <<p2<<" "<< &p2 <<endl;

    for (int i=0; i < 5; i++){
        p[i] = i+1;
        p2[i] = i+10;
    }

    for(int i=0; i<5; i++){
        cout<<*(p+4-i)<<endl;
    }

    for(int i=0; i<5; i++){
        cout<<*(p2+4-i)<<endl;
    }

    free(p);
}