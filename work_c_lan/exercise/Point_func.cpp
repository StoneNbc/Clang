#include<iostream>
using namespace std;
int * getPoint(){//返回值位一个地址

    int *p;
    int a = 1;
    cout<<"&a "<<&a<<endl;
    p = &a;
    return p;
}
int main(){
    int *p;
    p = getPoint();
    cout<<*p<<endl;//指向的地址的内容
    cout<<p<<endl;//指向的地址
    cout<<&p<<endl;//自己的地址
    return 0;
}