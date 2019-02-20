#include "stdio.h"
#include "stdlib.h"
#define N 50
#define LEN sizeof(Lnote)

typedef struct Personinfo  ElemType;


//创建结构体

struct Personinfo
{
	char *name;
	int  telephoneNumber;

};

typedef struct Lnote
{
	ElemType data;
	Lnote *next;
}RLinkList;

//声明所有函数
void initList(RLinkList * &L);//初始化单链表
void CrateListF(RLinkList * &L,ElemType e[],int n);//头插法创建环单lianbiao 
void CrateListR(RLinkList * &L,ElemType e[],int n);//尾插法创建环单lianbiao 
void DispList(RLinkList * L);//输出还列表
bool Empty(RLinkList *L);//判断环链表是否为Empty
int ListLength(RLinkList *L);//获得环链表的长度
bool GetElem(RLinkList *L,ElemType &e,int n);//返回第n个元素的值用e保存
int  LocalElem(RLinkList *L,ElemType e);//获得元素的位置
bool ListInsert(RLinkList *&L,ElemType e,int n); //在第n个元素的位置上插入元素e
bool ListDelete(RLinkList *&L,ElemType e,int n); //在第n个元素的位置上删除元素，用e保存元素


void initList(RLinkList * &L)//初始化单链表
{
	L=(RLinkList *)malloc(LEN);
	L->next=NULL;
}
void CrateListF(RLinkList * &L,ElemType e[],int n)//头插法创建环单lianbiao 
{
	int i;
	RLinkList *s,*head;

	for(i=0;i<n;i++)
	{
		s=(RLinkList *)malloc(LEN);
		s->data=e[i];
		s->next=L->next;
		if(i==0)
			head=s;
		L->next=s;
	}
	head->next=s;
}
void CrateListR(RLinkList * &L,ElemType e[],int n)//尾插法创建环单lianbiao 
{
	int i;
	RLinkList *r,*s;
	r=L;
	for(i=0;i<n;i++)
	{
		s=(RLinkList *)malloc(LEN);
		s->data=e[i];
		r->next=s;
		r=s;
	}
	s->next=L->next;
}
void DispList(RLinkList * L)//输出还列表
{	ElemType e;
	L=L->next;
	e=L->data;
	do
	{
		printf("%c ",L->data);
		L=L->next;
	}while(L!=NULL && L->data!=e);
	putchar ('\n');
}

bool Empty(RLinkList *L)//判断环链表是否为Empty
{
	if(L->next==NULL)return true;
	else return false;
}

int ListLength(RLinkList *L)//获得环链表的长度
{
	ElemType e;
	int n=0;
	if(L->next ==NULL)
	return 0;
	L=L->next;
	e=L->data;
	do
	{
		++n;
		L=L->next;
	}while(L!=NULL && L->data!=e);
	return n;
}
bool GetElem(RLinkList *L,ElemType &e,int n)//返回第n个元素的值用e保存
{
	int i=0;
	ElemType a;
	a=L->data;
	while(i<n && a!=L->next->data)
	{	++i;
		L=L->next;
	}
	if(a==L->next->data)
		return false;
	else 
	{
		e=L->data;
		return true;

	}
}
int  LocalElem(RLinkList *L,ElemType e)//获得元素的位置
{
	int i=0;
	ElemType a;
	a=L->data;
	while(L->data!=e && a!=L->next->data)
	{
		L=L->next;
		++i;
	}
	if(a==L->next->data)
		return (0);
	else 
		return i;

}

bool ListInsert(RLinkList *&L,ElemType e,int n) //在第n个元素的位置上插入元素e
{
	RLinkList *s,*p;
	ElemType a;
	int i=0;
	p=L;
	a=p->data;
	while(i<n && a!=p->next->data)
	{	++i;
		p=p->next;
	}
	if(a==p->next->data)
		return false;
	else
	{
		s=(RLinkList *)malloc(LEN);
		s->next=p->next;
		s->data=e;
		p->next=s;
		return true;
	}
}

bool ListDelete(RLinkList *&L,ElemType e,int n) //在第n个元素的位置上删除元素，用e保存元素
{
	RLinkList *s,*p;
	ElemType a;
	int i=0;
	p=L;
	a=p->data;
	while(i<n && a!=p->next->data)
	{	++i;
		p=p->next;
	}
	if(a==p->next->data)
		return false;
	else
	{	s=p->next;
		e=s->data;
		p->next=p->next;
		free(s);
		return true;
	}
}

int main(int argc,char *argv[])
{	
	int i=0;
	ElemType a[N]="abcde",e;
	RLinkList *h;
	initList(h);

	CrateListR(h,a,5);
	DispList(h);

	return 0;
}
