#include<iostream>

void test1(int x){
    x=1024;
    printf("无&符号 x的值为: %d\n",x);
}

void test2(int & x){
    x=2048;
    printf("有&符号 x的值为: %d\n",x);
}
int main(){
    int x = 1;
    printf("调用test前x=%d\n",x);
    test1(x);
    printf("调用无&后x=%d\n",x);
    test2(x);
    printf("调用有&后x=%d\n",x);
    return 0;
}