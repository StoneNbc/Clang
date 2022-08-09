#include<iostream>

using namespace std;



void reverse(int*a);

int main(){

    int a[2]={1,2};
    reverse(a);
    cout <<a[0] << " " << a[1] << " " << endl;
    return 0;
}
void reverse(int*a){
    int temp = 0;
    for(int i=0; i<2; i++){
        temp = a[i];
        a[i] = a[sizeof(a)/sizeof(int)-1];
        a[i+1] = temp;
    }
}