#include<iostream>
using namespace std;

typedef struct LNode
{
    /* data */
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitListNohead(LinkList L){//无头节点
    L = NULL;
    return true;
}
//初始化元素
bool InitListHasHead(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));//分配一个头节点
    if(L==NULL)//内存不足 分配失败
        return false;
    L->next = NULL;//头节点之后无节点
    return true;
}


LNode * GetElem(LinkList L, int i){
    int j=1;
    LNode * res = L->next;
    if (i == 0)
        return L;
    if (i < 0)
        return NULL;
    while(res != NULL && j<i){
        res = L->next;
        j++;
    }
    return res;
}

//插入元素
bool LinkInsert(LinkList &L, int i, int data){
    if(i<1)
        return false;
    LNode *p;
    p = L;
    int j =0;//目前第几个节点
    while (p!=NULL && j<i-1)//j<i-1 找到第i节点的上一个节点
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//p指向空则i值不合法
        return false;
    //开辟一个新节点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=data;//新节点的data赋值
    s->next=p->next;//将p之后的节点连在s节点后
    p->next=s;//将s节点连在p之后
    return true;
} 

// 指定节点的后插操作
bool InsertNextNode(LNode *p, int data){
    if(p=NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));//分配新节点
    if(s=NULL)//分配内存失败
        return false;
    s->data=data;//新节点的data赋值
    s->next=p->next;//将p之后的节点连在s节点后
    p->next=s;//将s节点连在p之后
    return true;
}

//指定节点的前插操作(偷天换日 后插交换)
bool InsertPriorNode(LNode *p, int data){
    if(p=NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));//分配新节点
    if(s=NULL)//分配内存失败
        return false;
    s->next=p->next;//将p之后的节点连在s节点后
    p->next=s;//将s节点连在p之后
    s->data=p->data;//将p节点的数据复制到s
    p->data=data;//将data赋值到p
    return true;
}
// 删除节点 带头节点
bool LinkDelete(LinkList &L, int i,int &data){
    if(i<1)
        return false;
    LNode *p;//扫描节点
    p = L;
    int j =0;//目前第几个节点
    while (p!=NULL && j<i-1)//j<i-1 找到第i节点的上一个节点
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//p指向空则i值不合法
        return false;
     if(p->next==NULL)//p下一个则i值不合法
        return false;

    LNode *q = p->next;//q指向被删除节点
    data=q->data;//用data返回节点值 假如p位最后一个节点 则此处报空指针
    p->next=q->next;//将*q节点从链中断开
    free(q);
    // p->next=p->next->next;
    return true;
}

// 按位查找
LNode * GetElemByLocation(LinkList L, int i){
    if(i<0)//头节点
        return NULL;
    LNode *p;//扫描节点
    p = L;
    int j =0;//目前第几个节点
    while (p!=NULL && j<i)// 找到第i节点
    {
        p=p->next;
        j++;
    }
    return p;
}
// 按值查找
LNode * GetElemByValue(LinkList L, int data){
    LNode *p = L->next;
    while (p != NULL && p->data==data)
    {
        p = p->next;
    }
    return p;
}
// 求表厂
int  getLength(LinkList L){
    int len=0;
    LNode *p = L;
    while (p != NULL )
    {
        p = p->next;
        len++;
    }
    return len;
}
//尾插法
LinkList List_Taillnsert(LinkList &L){//正向建立单链表
    int x;//设ElemType为整型
    L=(LinkList)malloc(sizeof(LNode));//建立头结点
    LNode *s,*r=L;//r为表尾指针
    scanf("%d",&x);//输入结点的值
    while(x!=9999){
        //输入9999表示结束
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;//r指向新的表尾结点
        scanf("%d" ,&x);
    }
    r->next=NULL;//尾结点指针置空
    return L;
}

//头插法
LinkList List_Headlnsert(LinkList &L){
    LNode *s;
    int x;//设ElemType为整型 
    L=(LinkList)malloc(sizeof(LNode));//建立头结点
    L->next=NULL;//初始空链表 防止脏数据
    scanf("%d",&x);//输入结点的值
    while(x!=9999){
        //输入9999表示结束
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;//将新节点插入表中，L为头指针
        scanf("%d" ,&x);
    }
    return L;
}





int main(){



    return 0;
}