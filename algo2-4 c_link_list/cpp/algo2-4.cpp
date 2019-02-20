#include "stdio.h"
#include "stdlib.h"
#define N 50
#define LEN sizeof(Lnote)

typedef struct Personinfo  ElemType;


//�����ṹ��

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

//�������к���
void initList(RLinkList * &L);//��ʼ��������
void CrateListF(RLinkList * &L,ElemType e[],int n);//ͷ�巨��������lianbiao 
void CrateListR(RLinkList * &L,ElemType e[],int n);//β�巨��������lianbiao 
void DispList(RLinkList * L);//������б�
bool Empty(RLinkList *L);//�жϻ������Ƿ�ΪEmpty
int ListLength(RLinkList *L);//��û�����ĳ���
bool GetElem(RLinkList *L,ElemType &e,int n);//���ص�n��Ԫ�ص�ֵ��e����
int  LocalElem(RLinkList *L,ElemType e);//���Ԫ�ص�λ��
bool ListInsert(RLinkList *&L,ElemType e,int n); //�ڵ�n��Ԫ�ص�λ���ϲ���Ԫ��e
bool ListDelete(RLinkList *&L,ElemType e,int n); //�ڵ�n��Ԫ�ص�λ����ɾ��Ԫ�أ���e����Ԫ��


void initList(RLinkList * &L)//��ʼ��������
{
	L=(RLinkList *)malloc(LEN);
	L->next=NULL;
}
void CrateListF(RLinkList * &L,ElemType e[],int n)//ͷ�巨��������lianbiao 
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
void CrateListR(RLinkList * &L,ElemType e[],int n)//β�巨��������lianbiao 
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
void DispList(RLinkList * L)//������б�
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

bool Empty(RLinkList *L)//�жϻ������Ƿ�ΪEmpty
{
	if(L->next==NULL)return true;
	else return false;
}

int ListLength(RLinkList *L)//��û�����ĳ���
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
bool GetElem(RLinkList *L,ElemType &e,int n)//���ص�n��Ԫ�ص�ֵ��e����
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
int  LocalElem(RLinkList *L,ElemType e)//���Ԫ�ص�λ��
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

bool ListInsert(RLinkList *&L,ElemType e,int n) //�ڵ�n��Ԫ�ص�λ���ϲ���Ԫ��e
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

bool ListDelete(RLinkList *&L,ElemType e,int n) //�ڵ�n��Ԫ�ص�λ����ɾ��Ԫ�أ���e����Ԫ��
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
