#include "stdio.h"
#include "stdlib.h"
#define LEN sizeof(LinkList)
#define N = 50;
typedef char ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkList;

//声明所有函数

void initLinkList(LinkList * &L); //初始化单链表
void CreateListF(LinkList * &L,ElemType a[],int i);//使用头插法创建单链表
void CreateListR(LinkList *&L,ElemType a[],int n); //使用尾插法创建单链表
void DestroyList(LinkList * &L);//销毁线性表
bool ListEmpty(LinkList *L); //判断单链表是否为空表 是返回1
void DisyList(LinkList *L); //输出链表
int ListLength(LinkList *L);//用n返回单链表的长度
bool GetElem(LinkList *L,int i,ElemType &e);//用e 返回第i个元素的值
int LocateElem(LinkList *L,ElemType e);//用i返回元素的物理位置
bool ListInsert (LinkList *&L,int i,ElemType e);//在第i个元素的位置插入元素e
bool ListDelete(LinkList * &L,int i,ElemType &e);//删除第i个元素的值 并用e保存

void initLinkList(LinkList * &L)//初始化单链表
{
	L=(LinkList *)malloc(LEN);
	L->next=NULL;
}

void DestroyList(LinkList * &L)//销毁线性表
{
	LinkList *pre=L,*p=L->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}


bool ListEmpty(LinkList *L) //判断单链表是否为空表 是返回1
{
	return (L->next==NULL);
}


void CreateListF(LinkList * &L,ElemType a[],int n)//使用头插法创建单链表
{	int i;
	LinkList *s;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(LEN);
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}

void CreateListR(LinkList *&L,ElemType a[],int n) //使用尾插法创建单链表
{	int i;

	LinkList *s,*r;
	r=L;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(LEN);
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}


void DisyList(LinkList * L)//输出单链表
{
	L=L->next; //尾插法的头没有任何数据
	while(L!=NULL)
	{
		printf("%c ",L->data);
		L=L->next;
	}
	putchar ('\n');
}

int ListLength(LinkList *L)//用n返回单链表的长度
{
	int n=0;
	while(L->next!=NULL)
	{
		++n;
		L=L->next;
	}
	return n;
}

bool GetElem(LinkList *L,int i,ElemType &e)//用e 返回第i个元素的值
{
	int j=0;
	LinkList *p=L;
	while(j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;

	else {
		e=p->data;
		return true;
	}
}

int LocateElem(LinkList *L,ElemType e)//用i返回元素的物理位置
{	int i=0;
	while(L->next != NULL && L->data!=e)
	{	L=L->next;
		++i;
	}
	if(L->next==NULL)  return (0);
	else return (i);
}

bool ListInsert (LinkList *&L,int i,ElemType e)//在第i个元素的位置插入元素e
{	
	int j=0;
	LinkList *p=L,*s;
	while(j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else 
	{	
		s=(LinkList *)malloc(LEN);
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}

bool ListDelete(LinkList * &L,int i,ElemType &e)//删除第i个元素的值 并用e保存
{
	int j=0;
	LinkList *p=L,*q;
	while(j<i-1 && p!=NULL)
	{
		++j;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else 
	{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}

int main(int avgc,char *avgv[])
{	int i=5;
	LinkList *h;
	ElemType a[50]={'a','b','c','d','e'};
	ElemType e;
	
	initLinkList(h);
	CreateListR(h,a,i);
	DisyList(h);
	printf("单链表的长度：%d\n",ListLength(h));
	ListEmpty(h)?printf("单链表h是空表\n"):printf("单链表h不是空表\n");
	GetElem(h,3,e);
	printf("%c\n",e);
	printf("元素a的位置：%d\n",LocateElem(h,'a'));
	ListInsert(h,4,'f');
	DisyList(h);
	ListDelete(h,3,e);
	DisyList(h);
	DestroyList(h);

	return 0;
}