#include<iostream>
using namespace std;


class OutOfRangeException{
    public:
        size_t error_pos;
        float error_num;

        OutOfRangeException(size_t pos, float num):error_pos(pos), error_num(num){}
        void print() {
            cout << "The parameter " << this->error_pos << " is " << this->error_num 
                 << " which is out of range (0-100)" << endl;
        }
};

float calculate(float * marks, size_t length=4){
    float sum = 0.0f;
    for (int i=0; i<length; i++){
        if (marks[i] < 0 || marks[i] > 100)
            throw OutOfRangeException(i+1, marks[i]);
        sum += marks[i];
    }
    return sum / length;
}


int main(){
    float marks[4];
    string control = "y";
    
    while (control == "y"){
        cout<<"Please enter marks for 4 courses: ";
        float res;
        bool flag = true;
        for(int i=0; i<4; i++){
            cin>>marks[i];
        }
        
        try{
            res = calculate(marks, 4);
        }
        catch (OutOfRangeException & e){
            e.print();
            flag = false;
        }

        if (flag)
            cout << "The average of the 4 courses is " << res << endl;

        cout << "Would you want to enter another 4 marks for 4 courses? (y/n) ";
        cin >> control;
        if (control == "n") {
            break;
        }
    }
    cout << "Bye, see you next time." << endl;
    return 0;
    
}