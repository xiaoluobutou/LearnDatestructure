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

//�������к���

void initLinkList(LinkList * &L); //��ʼ��������
void CreateListF(LinkList * &L,ElemType a[],int i);//ʹ��ͷ�巨����������
void CreateListR(LinkList *&L,ElemType a[],int n); //ʹ��β�巨����������
void DestroyList(LinkList * &L);//�������Ա�
bool ListEmpty(LinkList *L); //�жϵ������Ƿ�Ϊ�ձ� �Ƿ���1
void DisyList(LinkList *L); //�������
int ListLength(LinkList *L);//��n���ص�����ĳ���
bool GetElem(LinkList *L,int i,ElemType &e);//��e ���ص�i��Ԫ�ص�ֵ
int LocateElem(LinkList *L,ElemType e);//��i����Ԫ�ص�����λ��
bool ListInsert (LinkList *&L,int i,ElemType e);//�ڵ�i��Ԫ�ص�λ�ò���Ԫ��e
bool ListDelete(LinkList * &L,int i,ElemType &e);//ɾ����i��Ԫ�ص�ֵ ����e����

void initLinkList(LinkList * &L)//��ʼ��������
{
	L=(LinkList *)malloc(LEN);
	L->next=NULL;
}

void DestroyList(LinkList * &L)//�������Ա�
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


bool ListEmpty(LinkList *L) //�жϵ������Ƿ�Ϊ�ձ� �Ƿ���1
{
	return (L->next==NULL);
}


void CreateListF(LinkList * &L,ElemType a[],int n)//ʹ��ͷ�巨����������
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

void CreateListR(LinkList *&L,ElemType a[],int n) //ʹ��β�巨����������
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


void DisyList(LinkList * L)//���������
{
	L=L->next; //β�巨��ͷû���κ�����
	while(L!=NULL)
	{
		printf("%c ",L->data);
		L=L->next;
	}
	putchar ('\n');
}

int ListLength(LinkList *L)//��n���ص�����ĳ���
{
	int n=0;
	while(L->next!=NULL)
	{
		++n;
		L=L->next;
	}
	return n;
}

bool GetElem(LinkList *L,int i,ElemType &e)//��e ���ص�i��Ԫ�ص�ֵ
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

int LocateElem(LinkList *L,ElemType e)//��i����Ԫ�ص�����λ��
{	int i=0;
	while(L->next != NULL && L->data!=e)
	{	L=L->next;
		++i;
	}
	if(L->next==NULL)  return (0);
	else return (i);
}

bool ListInsert (LinkList *&L,int i,ElemType e)//�ڵ�i��Ԫ�ص�λ�ò���Ԫ��e
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

bool ListDelete(LinkList * &L,int i,ElemType &e)//ɾ����i��Ԫ�ص�ֵ ����e����
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
	printf("������ĳ��ȣ�%d\n",ListLength(h));
	ListEmpty(h)?printf("������h�ǿձ�\n"):printf("������h���ǿձ�\n");
	GetElem(h,3,e);
	printf("%c\n",e);
	printf("Ԫ��a��λ�ã�%d\n",LocateElem(h,'a'));
	ListInsert(h,4,'f');
	DisyList(h);
	ListDelete(h,3,e);
	DisyList(h);
	DestroyList(h);

	return 0;
}