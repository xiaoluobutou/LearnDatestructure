#include <stdlib.h>
#include <stdio.h>

#define C getchar()
#define NULL 0
#define ST struct student
#define M printf("\n*********************************\n")
typedef char ElemType;

struct student
{
	char data;
	struct student *next;
};

ST *InitList()
{	
	ST *h;
	h = (ST*)malloc(sizeof(ST));
	h->next = NULL;
	return h;
}

void DestroyList(ST *h)
{
	ST *p = h,*q = p->next;
	while(q != NULL)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(q);
}

int ListEmpty(ST *h)
{
	return (h->next == NULL);
}

void DispList(ST *h)
{
	ST *q = h->next;
	while(q != NULL)
	{
		printf(" %c",q->data);
		q=q->next;
	}
	printf("\n");
}

ElemType GetElem(ST *h,int i)
{
	int j = 0;
	ST *q = h;
	ElemType e;
	while (j!=i && q!=NULL)
	{
		j++;
		q=q->next;
	}
	if(q==NULL)
		return 0;
	else
	{
		e=q->data;
		return e;
	}
}

int LocateElem(ST *h,ElemType e)
{
	int j = 0;
	ST *q = h->next;
	while(q!=NULL && e!=q->data)
	{
		j++;
		q++;
	}
	if(q==NULL)
		return 0;
	else 
		return j;
}

int InsertElem(ST *h,int n,ElemType e)
{
	int j = 0;
	ST *q = h->next;
	ST *s;
	while(j<n-1 && q!=NULL)
	{
		j++;
		q=q->next;
	}
	if(q==NULL)
		return 0;
	else 
	{
		s=(ST *)malloc(sizeof(ST));
		s->data=e;
		s->next=q->next;
		q->next=s;
		return 1;
	}
}

int ListLength(ST *h)
{
	int j = 0;
	ST *q=h;
	while(q!=NULL)
	{
		j++;
		q=q->next;
	}
	return j;
}

void ListInsertH(ST *h,ElemType e)
{
	ST *s;
	s = (ST*)malloc(sizeof(ST));
	s->data = e;
	s->next = h->next;
	h->next = s;
}
void ListChange(ST *h)
{
	ST *p,*q;
	p=h->next;
	q=h->next;
	h->next=NULL;
	while(p)
	{
		p->next=h->next;
		h->next=p;
		p=q;
		q=q->next;
	}
}
int main()
{
	
	return 0;
}