#include<iostream>

#define MaxSize 10

using namespace std;

typedef struct{
    int data[MaxSize];
    int length;
}Sqlist;
//初始化顺序表
void InitList(Sqlist &L){
    L.length=0;
}



//插入一个元素
bool ListInsert(Sqlist &L, int n, int i){
    if(i<1 || i>L.length+1 || L.length>=MaxSize)//插入位置异常或已满
        return false;
    for(;i<=L.length;i++){
        L.data[i] = L.data[i-1];
    }
    L.data[i-1]=n;
    L.length++;
    return true;
}

bool ListDelete(Sqlist &L, int i ,int & e){
    if(i<1 || i>L.length)//删除位次范围是否有效
        return false;
    e=L.data[i-1];//将被删除的赋值给e
    for(;i<=L.length;i++){
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}
//按位查找
int ListQueryLocation(Sqlist &L, int i){
    return L.data[i-1];
}

//按值查找
int ListQueryValue(Sqlist &L, int i){
    for(int j=0; j<L.length;j++){
        if(L.data[j]==i)
        return j+1;
    }
    return 0;
}



int main(){
    Sqlist L;
    
    InitList(L);
    for(int i = 0;i<MaxSize;i++){
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    return 0;
}