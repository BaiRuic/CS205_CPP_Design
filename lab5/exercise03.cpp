#include<iostream>
using std::cout;
using std::endl;

bool isPrime(int num){
    for (int i=1+1; i<=num-1; i++)
        if(num % i ==0)
            return false;
    return true;    
}

int main(){
    int a = 2;
    cout<<isPrime(a)<<endl;
    return 0;
}