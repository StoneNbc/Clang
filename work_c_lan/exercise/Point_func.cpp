#include<iostream>
using namespace std;
int * getPoint(){//����ֵλһ����ַ

    int *p;
    int a = 1;
    cout<<"&a "<<&a<<endl;
    p = &a;
    return p;
}
int main(){
    int *p;
    p = getPoint();
    cout<<*p<<endl;//ָ��ĵ�ַ������
    cout<<p<<endl;//ָ��ĵ�ַ
    cout<<&p<<endl;//�Լ��ĵ�ַ
    return 0;
}