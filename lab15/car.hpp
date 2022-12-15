#ifndef __CAR_HPP__
#define __CAR_HPP__

#include<iostream>

class Driver;
class Car;

class Car{
    friend class Driver;
    private:
        int mode; // mode of car, 0 or 1;
        int velocity;
        enum {off=0, on=1};
        enum {Minvel, Maxvel=200};
    public:
        Car(int m=off, int v=Maxvel): mode(m), velocity(v) {}
        bool velup(int v);
        bool veldown(int v);
        bool ison() const;
        void showInf() const;
};

class Driver{
    private:
    
    public:
        bool velup(Car & car, int v);
        bool veldown(Car & car, int v);
        void setMode(Car & car);
        bool ison(Car & car);

};


#endif