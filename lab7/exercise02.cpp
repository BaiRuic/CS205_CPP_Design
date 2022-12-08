#include<iostream>

using namespace std;

int vabs(int *p, int n);
float vabs(float *p, int n);
double vabs(double *p, int n);

int main(){
    int a[5] = {6, 4, 2, 6, 3};
    float b[5] = {6.5f, 7.4f, -4.5f, -1.3f, 5.9f};
    double c[5] = {5.0, 3.6, 6.7, 8.9, -100.6};

    cout<<vabs(a, 5)<<endl;
    cout<<vabs(b, 5)<<endl;
    cout<<vabs(c, 5)<<endl;
}

int vabs(int *p, int n){
    int res = 0;
    for(int i=0; i<n; i++)
        res += abs(p[i]);
    return res;
}


float vabs(float *p, int n){
    float res = 0.0f;
    for(int i=0; i<n; i++){
        if (p[i] < 0)
            res -= p[i];
        else
            res += p[i];
    }
    return res;
}


double vabs(double *p, int n){
    double res = 0.0f;
    for(int i=0; i<n; i++){
        if (p[i] < 0)
            res -= p[i];
        else
            res += p[i];
    }
    return res;
}