#include "stdio.h"
#include "stdlib.h"
#define LEN sizeof(DLinkList)
#define N 50

typedef char ElemType;

typedef struct Lnode
{
	ElemType data;
	Lnode *next;
	Lnode *prior;
}DLinkList;

//声明所有函数
void initDLinkList(DLinkList * &L); //初始化双链表
void CreatListF(DLinkList * &L,ElemType a[],int n);//使用头插法创建双链表
void CreatListR(DLinkList * &L,ElemType a[],int n);//使用尾插法创建双链表
void DispList(DLinkList *L);//输出双链表
int ListLength(DLinkList *L);//输出双链表的长度
bool ListEmpty(DLinkList *L);//判断双链表是否为空
bool GetElem(DLinkList *L,int i,ElemType &e);//返回第i个位置的元素的值
void DestoyList(DLinkList * &L);//销毁双链表
bool ListInsert(DLinkList * &L,int i,ElemType e);//在i的位置插入元素e
bool ListDelete(DLinkList * &L,int i,ElemType &e); //删除i的元素用e保存

void initDLinkList(DLinkList * &L) //初始化双链表
{
	L=(DLinkList *)malloc(LEN);
	L->next=L->prior=NULL;
}

void CreatListF(DLinkList * &L,ElemType a[],int n)//使用头插法创建双链表
{
	DLinkList *s;
	int i;
	for(i=0;i<n;i++)
	{
		s=(DLinkList *)malloc(LEN);
		s->data=a[i];
		s->next=L->next;
		if(L->next!=NULL)
		{
			L->next->prior=s;
		}
		L->next=s;
		s->prior=NULL;

	}
}

void CreatListR(DLinkList * &L,ElemType a[],int n)//使用尾插法创建双链表
{
	DLinkList *s,*r;
	int i;
	r=L;
	for(i=0;i<n;i++)
	{
		s=(DLinkList *)malloc(LEN);
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	s->next=NULL;
}

void DispList(DLinkList *L)//输出双链表
{
	
	L=L->next;
	printf("双链表元素为：");
	while(L!=NULL)
	{
		printf("%c ",L->data);
		L=L->next;
	}
	putchar ('\n');
}

int ListLength(DLinkList *L)//输出双链表的长度
{
	int i=0;
	L=L->next;
	while(L!=NULL)
	{
		++i;
		L=L->next;
	}
	return i;
}

bool ListEmpty(DLinkList * L)//判断双链表是否是空表
{
	if(L->next==NULL)return 1;
	else return 0;
}

bool GetElem(DLinkList *L,int i,ElemType &e)//返回第i个位置的元素的值
{	int j=0;
	
	while(j<i && L!=NULL)
	{
		++j;
		L=L->next;
	}
	if(L == NULL)
		return false;
	else 
	{
		e=L->data;
		return true;
	}
}

void DestoyList(DLinkList * &L)//销毁双链表
{
	DLinkList *q;
	while(L->next!=NULL)
	{
		q=L;
		L=L->next;
		free(q);
	}
}
/*
void DestoyList(DLinkList * &L)//销毁双链表
{
	DLinkList *p,*q;
	p=L;
	q=L->next;
	while(q!=NULL)
	{
		free(p);
		p=NULL;
		p=q;
		q=q->next;
	}
	free(q);
}
*/
bool ListInsert(DLinkList * &L,int i,ElemType e)//在i的位置插入元素e
{
	DLinkList *s,*p;
	int j=0;
	--i;					//插入和删除都要减一
	p=L;
	while(j<i && p!=NULL)
	{
		++j;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		s=(DLinkList *)malloc(LEN);
		s->data=e;
		s->next=p->next;
		if(p->next!=NULL)
			p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
}

bool ListDelete(DLinkList * &L,int i,ElemType &e) //删除i的元素用e保存
{
	int j=0;
	--i;					//插入和删除都要减一
	DLinkList *p,*s;
	p=L;
	while(j<i && p!=NULL)
	{
		++j;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else 
	{	s=p->next;
		if(s==NULL)
			return false;
		e=s->data;
		p->next=s->next;
		if(p->next!=NULL)
			p->next->prior=p;
		free(s);
		return true;
	}
}

int main(int argc, char *argv[])
{	int i=4;
	DLinkList *h;
	ElemType a[N] ={"abcde"};
	ElemType e;
	initDLinkList(h);
	CreatListR(h,a,5);


	DispList(h);
	printf("双链表的长度为%d \n",ListLength(h));
	ListEmpty(h)?printf("双链表为空表\n"):printf("双链表不是空表\n");
	printf("%d\n",GetElem(h,3,e));
	printf("%c\n",e);
	printf("在第%d位插入字符f后：",i);
	ListInsert(h,4,'f');
	DispList(h);
	printf("在第%d位删除字符f后：",i);
	ListDelete(h,i,e);
	DispList(h);

	DestoyList(h);
	ListEmpty(h)?printf("双链表为空表\n"):printf("双链表不是空表\n");

	return 0;
}
