#include "stdio.h"
#include "stdlib.h"
#define N 50
#define LEN sizeof(LNode)

typedef char ElemType;

//创建结构体
typedef struct LNode
{
	ElemType data;
	LNode *prior;
	LNode *next;
}RDLinkList;

//声明所有函数
void initList( RDLinkList * &L);//初始化环双链表


void initList(RDLinkList * &L)//初始化环双链表
{
	L=(RDLinkList *)malloc(LEN);
	L->prior=L->next=NULL;
} 

void CreateListF(RDLinkList * &L,ElemType a[],int n)//使用头插法创建还单链表
{
	RDLinkList *s,*head;
	int i;
	for(i=0;i<n;i++)
	{
		s=(RDLinkList *)malloc(LEN);
		s->data=a[i];
		s->next=L->next;
		if(i==0)
			head=s;
		if(L->next!=NULL)
		{
			L->next->prior=s;
		}
		L->next=s;
		s->prior=NULL;
	}
	s->next=head;
	head->prior=s;
}

int main(int argc,char *argv[])
{	

	RDLinkList *h;
	ElemType a[N]="abcde";
	ElemType e;
	initList(h);
	return 0;
}