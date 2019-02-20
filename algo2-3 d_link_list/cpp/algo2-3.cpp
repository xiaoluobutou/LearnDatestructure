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

//�������к���
void initDLinkList(DLinkList * &L); //��ʼ��˫����
void CreatListF(DLinkList * &L,ElemType a[],int n);//ʹ��ͷ�巨����˫����
void CreatListR(DLinkList * &L,ElemType a[],int n);//ʹ��β�巨����˫����
void DispList(DLinkList *L);//���˫����
int ListLength(DLinkList *L);//���˫����ĳ���
bool ListEmpty(DLinkList *L);//�ж�˫�����Ƿ�Ϊ��
bool GetElem(DLinkList *L,int i,ElemType &e);//���ص�i��λ�õ�Ԫ�ص�ֵ
void DestoyList(DLinkList * &L);//����˫����
bool ListInsert(DLinkList * &L,int i,ElemType e);//��i��λ�ò���Ԫ��e
bool ListDelete(DLinkList * &L,int i,ElemType &e); //ɾ��i��Ԫ����e����

void initDLinkList(DLinkList * &L) //��ʼ��˫����
{
	L=(DLinkList *)malloc(LEN);
	L->next=L->prior=NULL;
}

void CreatListF(DLinkList * &L,ElemType a[],int n)//ʹ��ͷ�巨����˫����
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

void CreatListR(DLinkList * &L,ElemType a[],int n)//ʹ��β�巨����˫����
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

void DispList(DLinkList *L)//���˫����
{
	
	L=L->next;
	printf("˫����Ԫ��Ϊ��");
	while(L!=NULL)
	{
		printf("%c ",L->data);
		L=L->next;
	}
	putchar ('\n');
}

int ListLength(DLinkList *L)//���˫����ĳ���
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

bool ListEmpty(DLinkList * L)//�ж�˫�����Ƿ��ǿձ�
{
	if(L->next==NULL)return 1;
	else return 0;
}

bool GetElem(DLinkList *L,int i,ElemType &e)//���ص�i��λ�õ�Ԫ�ص�ֵ
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

void DestoyList(DLinkList * &L)//����˫����
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
void DestoyList(DLinkList * &L)//����˫����
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
bool ListInsert(DLinkList * &L,int i,ElemType e)//��i��λ�ò���Ԫ��e
{
	DLinkList *s,*p;
	int j=0;
	--i;					//�����ɾ����Ҫ��һ
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

bool ListDelete(DLinkList * &L,int i,ElemType &e) //ɾ��i��Ԫ����e����
{
	int j=0;
	--i;					//�����ɾ����Ҫ��һ
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
	printf("˫����ĳ���Ϊ%d \n",ListLength(h));
	ListEmpty(h)?printf("˫����Ϊ�ձ�\n"):printf("˫�����ǿձ�\n");
	printf("%d\n",GetElem(h,3,e));
	printf("%c\n",e);
	printf("�ڵ�%dλ�����ַ�f��",i);
	ListInsert(h,4,'f');
	DispList(h);
	printf("�ڵ�%dλɾ���ַ�f��",i);
	ListDelete(h,i,e);
	DispList(h);

	DestoyList(h);
	ListEmpty(h)?printf("˫����Ϊ�ձ�\n"):printf("˫�����ǿձ�\n");

	return 0;
}
