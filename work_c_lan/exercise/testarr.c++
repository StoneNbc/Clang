#include<iostream>

using namespace std;



void setarr(int a[]);

int main(){

    int a[3];
    setarr(a);
    cout <<a[0] << " " << a[1] << " " << endl;
    return 0;
}
void setarr(int a[]){
    for(int i=0;i<2;i++){
        cin>>a[i];
    }
    cout<<sizeof(&a)<<endl;
}