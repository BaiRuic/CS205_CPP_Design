#include"CStereoShape.hpp"

using namespace std;

int main(){
    CCube a_cube(4.0f, 5.0f, 6.0f);
    CSphere c_sphere(7.9);
    CStereoShape *p = & a_cube;
    p->Show();

    p = &c_sphere;
    p->Show();

    cout<<p->GetNumOfObject()<<endl;
}
