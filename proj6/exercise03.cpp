#include<iostream>
using std::cout;
using std::cin;
using std::endl;

struct Point{
    float x;
    float y;
};

Point createPoint(float x, float y){
    Point p = {.x=x, .y=y};
    return p;
}

Point getMid(Point & p1, Point & p2){
    float x_ = (p1.x + p2.x) / 2;
    float y_ = (p1.y + p2.y) / 2;
    Point p = createPoint(x_, y_);
    return p;
}

int main(){
    Point p1 = createPoint(23, 23);
    Point p2 = createPoint(1, 9);

    Point pm = getMid(p1, p2);
    cout<<'('<<pm.x<<","<<pm.y<<')'<<endl;

    return 0;
}