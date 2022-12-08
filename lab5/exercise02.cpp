#include<iostream>
using namespace std;

int main(){
    char *p = (char *)malloc(5 * sizeof(char));
    
    // char 类型 超过了255会乱码；
    for (int i=0; i<5; i++){
        *(p+i) = 254+i;
    }

    //最后一个字符作为字符串结尾
    p[4] = '\0';
    cout<<"output:"<<p;
    
    free(p);
    return 0;
}
