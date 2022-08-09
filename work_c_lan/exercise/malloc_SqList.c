#include<iostream>

#define InitSize 10

typedef struct malloc_SqList
{
    /* data */
    int *data;
    int MaxSize;
    int length;
}malloc_SqList;
//初始化
void InitList( malloc_SqList L){
    L.data=(int)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize=InitSize;
}
//增加size，传入结构体和需要增加的长度
void AddSize(malloc_SqList L, int len){
    int *p=L.data;
    L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0; i<L.length;i++){
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

//按位查找
int ListQueryLocation(malloc_SqList L, int i){
    return L.data[i-1];
}

//按值查找
int ListQueryValue(malloc_SqList L, int i){
    for(int j=0; j<L.length;j++){
        if(L.data[j]==i)
        return j+1;
    }
    return 0;
}


int main(){

     malloc_SqList L;//声名一个顺序表
     InitList(L);//初始化
     AddSize(L,5);    
     return 0;
 }