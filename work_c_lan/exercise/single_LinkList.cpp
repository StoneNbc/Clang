#include<iostream>
using namespace std;

typedef struct LNode
{
    /* data */
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitListNohead(LinkList L){//��ͷ�ڵ�
    L = NULL;
    return true;
}
//��ʼ��Ԫ��
bool InitListHasHead(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));//����һ��ͷ�ڵ�
    if(L==NULL)//�ڴ治�� ����ʧ��
        return false;
    L->next = NULL;//ͷ�ڵ�֮���޽ڵ�
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

//����Ԫ��
bool LinkInsert(LinkList &L, int i, int data){
    if(i<1)
        return false;
    LNode *p;
    p = L;
    int j =0;//Ŀǰ�ڼ����ڵ�
    while (p!=NULL && j<i-1)//j<i-1 �ҵ���i�ڵ����һ���ڵ�
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//pָ�����iֵ���Ϸ�
        return false;
    //����һ���½ڵ�
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=data;//�½ڵ��data��ֵ
    s->next=p->next;//��p֮��Ľڵ�����s�ڵ��
    p->next=s;//��s�ڵ�����p֮��
    return true;
} 

// ָ���ڵ�ĺ�����
bool InsertNextNode(LNode *p, int data){
    if(p=NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));//�����½ڵ�
    if(s=NULL)//�����ڴ�ʧ��
        return false;
    s->data=data;//�½ڵ��data��ֵ
    s->next=p->next;//��p֮��Ľڵ�����s�ڵ��
    p->next=s;//��s�ڵ�����p֮��
    return true;
}

//ָ���ڵ��ǰ�����(͵�컻�� ��彻��)
bool InsertPriorNode(LNode *p, int data){
    if(p=NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));//�����½ڵ�
    if(s=NULL)//�����ڴ�ʧ��
        return false;
    s->next=p->next;//��p֮��Ľڵ�����s�ڵ��
    p->next=s;//��s�ڵ�����p֮��
    s->data=p->data;//��p�ڵ�����ݸ��Ƶ�s
    p->data=data;//��data��ֵ��p
    return true;
}
// ɾ���ڵ� ��ͷ�ڵ�
bool LinkDelete(LinkList &L, int i,int &data){
    if(i<1)
        return false;
    LNode *p;//ɨ��ڵ�
    p = L;
    int j =0;//Ŀǰ�ڼ����ڵ�
    while (p!=NULL && j<i-1)//j<i-1 �ҵ���i�ڵ����һ���ڵ�
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//pָ�����iֵ���Ϸ�
        return false;
     if(p->next==NULL)//p��һ����iֵ���Ϸ�
        return false;

    LNode *q = p->next;//qָ��ɾ���ڵ�
    data=q->data;//��data���ؽڵ�ֵ ����pλ���һ���ڵ� ��˴�����ָ��
    p->next=q->next;//��*q�ڵ�����жϿ�
    free(q);
    // p->next=p->next->next;
    return true;
}

// ��λ����
LNode * GetElemByLocation(LinkList L, int i){
    if(i<0)//ͷ�ڵ�
        return NULL;
    LNode *p;//ɨ��ڵ�
    p = L;
    int j =0;//Ŀǰ�ڼ����ڵ�
    while (p!=NULL && j<i)// �ҵ���i�ڵ�
    {
        p=p->next;
        j++;
    }
    return p;
}
// ��ֵ����
LNode * GetElemByValue(LinkList L, int data){
    LNode *p = L->next;
    while (p != NULL && p->data==data)
    {
        p = p->next;
    }
    return p;
}
// ���
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
//β�巨
LinkList List_Taillnsert(LinkList &L){//������������
    int x;//��ElemTypeΪ����
    L=(LinkList)malloc(sizeof(LNode));//����ͷ���
    LNode *s,*r=L;//rΪ��βָ��
    scanf("%d",&x);//�������ֵ
    while(x!=9999){
        //����9999��ʾ����
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;//rָ���µı�β���
        scanf("%d" ,&x);
    }
    r->next=NULL;//β���ָ���ÿ�
    return L;
}

//ͷ�巨
LinkList List_Headlnsert(LinkList &L){
    LNode *s;
    int x;//��ElemTypeΪ���� 
    L=(LinkList)malloc(sizeof(LNode));//����ͷ���
    L->next=NULL;//��ʼ������ ��ֹ������
    scanf("%d",&x);//�������ֵ
    while(x!=9999){
        //����9999��ʾ����
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;//���½ڵ������У�LΪͷָ��
        scanf("%d" ,&x);
    }
    return L;
}





int main(){



    return 0;
}