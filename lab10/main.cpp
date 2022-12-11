#include"complex.hpp"
using namespace std;
    
int main(){
    cout<<"input two number as real and imag:"<<endl;
    Complex c1;
    cin>>c1;

    cout<<"input two number as real and imag:"<<endl;
    Complex c2;
    cin>>c2;
    
    Complex c3 = c1+c2;

    cout<<c1;
    cout<<c2;
    cout<<c3;
    
    return 0;
}