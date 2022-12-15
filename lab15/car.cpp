#include"car.hpp"
using namespace std;


bool Car::velup(int v){
    if (velocity + v > Maxvel) {
        cout << "Out of Maxvel!!!" << endl;
        return false;
    }
    this->velocity += v;
    return true;
}

bool Car::veldown(int v){
    if (velocity - v < Minvel) {
        cout << "Out of Maxvel!!!" << endl;
        return false;
    }
    this ->velocity -= v;
    return true;
}

bool Car::ison() const {
    return this->mode;
}

void Car::showInf() const{
    cout<<"A car with speed "<<velocity<<", and the autodriver is "<<(mode==0?"on":"off")<<endl;
}



bool Driver::velup(Car & car, int v){
    if (car.velocity + v > car.Maxvel) {
        cout << "Out of Maxvel!!!" << endl;
        return false;
    }
    car.velocity += v;
    return true;
}

bool Driver::veldown(Car & car, int v){
    if (car.velocity - v < car.Minvel) {
        cout << "Out of Maxvel!!!" << endl;
        return false;
    }
    car.velocity -= v;
    return true;
}

void Driver::setMode(Car & car){
    car.mode = !car.mode;
}

bool Driver::ison(Car & car){
    return car.mode;
}

