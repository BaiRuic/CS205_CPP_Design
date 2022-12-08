#include<iostream>
using namespace std;

template<typename T>
inline
T minimum(T a, T b){
    if (a < b)
        return a;
    return b;
}

int main(){
    cout<<minimum(5.6f, 7.8f)<<endl;
    cout<<minimum(345, 23)<<endl;
    cout<<minimum(234.2412, 342.232)<<endl;
}