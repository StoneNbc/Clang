#include<iostream>

using namespace std;

int main(){
    int a=1;
    cout<<" &a "<<&a<<endl;
    int *p;
    p = &a;//指向a （的地址）
    cout<<"p = &a "<<p<<" 等于a的地址 &a "<<endl;
    cout<<"p = &a "<< *p<<" 等于a的值 1 "<<endl;
    int *b;
    *b = a;//b指向的地址的值等于a
    cout<<"*b=a "<<b<<" 等于b指向的地址 "<<endl;
    cout<<"*b=a "<<*b<< " 等于1 "<<endl;
    cout<<" &b "<<b<<endl;
}