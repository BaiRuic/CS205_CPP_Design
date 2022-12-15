#include<iostream>
#include"car.hpp"

int main(int argc, char const* argv[]) {
    Car car;
    Driver driver;

    car.showInf();
    car.velup(120);
    driver.setMode(car);
    car.showInf();
    driver.veldown(car, 100);
    driver.velup(car, 150);
    car.showInf();
    return 0;
}