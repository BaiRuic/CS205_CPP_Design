#include<iostream>
using std::cout;
using std::endl;
using std::cin;

char * match(char * s, char ch){
    char * p = s;
    // 0 是字符串的结尾
    while (*p != 0){
        if (*p == ch)
            return p;
        p++;
    }
    return NULL;
}


int main(){
    char s[200];
    char ch;
    cout<<"Please input a string:"<<endl;
    cin.getline(s, 200);
    //cout<<s<<endl;
    cout<<"Please input a character:"<<endl;
    ch = getchar();

    char * res = match(s, ch);
    if (res != NULL)
        cout<<res<<endl;
    else
        cout<<"Not Found"<<endl;
    
    return 0;
}