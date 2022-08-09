#include<iostream>

using namespace std;

void checkshape(int a, int b ,int c){
	if((a==b && a !=c) || (a==c && a !=b) || (c==b && a !=c))
		cout<<"等腰"<<endl;
	if(a==b && b==c)
		cout<<"等边"<<endl;

}

int main(){

	while(1){
		int a=0;
		int b=0;
		int c=0;
		cout<<"请输入abc"<<endl;
		cin>>a>>b>>c;
		while( a<1||a>200 ){
			cout<<"a 必须在1到200之间"<<endl;
			cin>>a;
		}
		while( b<1||b>200 ){
			cout<<"b 必须在1到200之间"<<endl;
			cin>>b;
		}
		while( b<1||b>200 ){
			cout<<"c 必须在1到200之间"<<endl;
			cin>>c;
		}

		while(a+c<=b){
			cout<<"a + c must > b"<<endl;
			cin>>a>>b>>c;
		}
		while(c+b<=a){
			cout<<"c + b must > a"<<endl;
			cin>>a>>b>>c;
		}
		while(a+b<=c){
			cout<<"a + b must > c"<<endl;
			cin>>a>>b>>c;
		}

		checkshape(a,b,c);
	}
    return 0;
}
