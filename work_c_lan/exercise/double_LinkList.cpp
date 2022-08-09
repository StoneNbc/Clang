#include<iostream>
typedef struct LNode
{
    /* data */
    int data;
    struct LNode *next, *prior;
}LNode, *LinkList;

//初始化元素
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));//分配一个头节点
    if(L==NULL)//内存不足 分配失败
        return false;
    L->next = NULL;//头节点之后无节点
    L->prior = NULL;//头节点之无节点
    return true;
} 

//p节点后插入s节点
bool InsertNextNode(LNode *p, LNode *s){
    if(p == NULL && s == NULL)
        return false;
    s->next=p->next;
    if(p->next !=NULL)//p指针无后继结点
        p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
} 

// 删除p节点后继节点
bool LinkDelete(LNode *p){
    if(p == NULL)
        return false;
    LNode *q = p->next;//存放p的下一节点
    if(q==NULL)
        return false;
    p->next=q->next;
    if(q->next!=NULL)//q无后继节点
        q->next->prior=q;
    free(q);
    return true;
}
// 销毁双链表
void DestoryList(LinkList &L){
    while (L->next!=NULL)//循环释放各个节点
    {
        LinkDelete(L);
    }
    free(L);//释放头节点
    L=NULL;//头指针指向NULL
}

// 遍历


int main(){

}