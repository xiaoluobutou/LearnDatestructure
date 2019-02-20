#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
}LiStack;

//����ȫ������
void InitStack(LiStack * &s);//��ʼ��ջ
void Destory(LiStack * &s);//����ջ
bool StackEmpty(LiStack *s);//�ж���ջ�Ƿ�Ϊ��
void Push (LiStack * &s,ElemType e);//��ջ
bool Pop(LiStack * &s,ElemType e);//��ջ
bool GetTop(LiStack *s,ElemType &e);//ȡջ��Ԫ��
int StackLength(LiStack *s);//ջ�ĳ���
void DispStack(LiStack *s);//�����ջ��Ԫ��
void OrderStack(LiStack *s);//�����ջ������

void InitStack(LiStack * &s)//��ʼ����ջ
{
	s=(LiStack *)malloc(sizeof(LiStack));
	s->next=NULL;
}

void Destory(LiStack * &s)//������ջ
{
	LiStack  *p=s;
	LiStack  *q=s->next;
	while(q!=NULL)
	{
		free(p);
		p=q;
		q=q->next;
	}
	free(p);
}

bool StackEmpty(LiStack *s)//�ж���ջ�Ƿ�Ϊ��
{
	return (s->next==NULL);
}
void Push (LiStack * &s,ElemType e)//��ջ
{
	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;
	p->next=s->next;
	s->next=p;
}

bool Pop(LiStack * &s,ElemType e)//��ջ
{
	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	if(s->next==NULL)
		return false;
	p=s->next;
	s->next=p->next;
	free(p);
	return true;
}

bool GetTop(LiStack *s,ElemType &e)//ȡջ��Ԫ��
{
	if(s->next==NULL)
		return false;
	e=s->next->data;
	return true;
}

int StackLength(LiStack *s)//����ջ�ĳ���
{
	int n=0;
	s=s->next;
	while(s!=NULL)
	{
		++n;
		s=s->next;
	}
	return n;
}

void DispStack(LiStack *s)//�����ջ��Ԫ��
{
	s=s->next;
	while(s!=NULL)
	{
		printf("%c ",s->data);
		s=s->next;
	}
	putchar('\n');
}

void OrderStack(LiStack *s)//�����ջ������
{
	int n=0;
	s=s->next;
	while(s!=NULL)
	{
		printf("%d ",++n);
		s=s->next;
	}
	putchar('\n');
}

int main(int argc,char *argv[])
{
	LiStack *s;
	ElemType e;
	InitStack(s);
	StackEmpty(s)?printf("StackEmpty\n"):printf("not StackEmpty\n"); 
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	StackEmpty(s)?printf("StackEmpty\n"):printf("not StackEmpty\n"); 
	printf("%d\n",StackLength(s));
	DispStack(s);
	OrderStack(s);
	StackEmpty(s)?printf("StackEmpty\n"):printf("not StackEmpty\n"); 
	Destory(s);
	return 0;
}
