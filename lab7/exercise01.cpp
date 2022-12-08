#include<iostream>
using namespace std;

void displaySquare(int side=5, char filledCharacter='#');


int main(){
    displaySquare();
    displaySquare(6, '*');
    return 0;
}

void displaySquare(int side, char filledCharacter){
    for(int i=0; i<side; i++){
        for (int j=0; j< side; j++){
            cout<<filledCharacter;
        }
        cout<<endl;
    }
    cout<<endl;
}


