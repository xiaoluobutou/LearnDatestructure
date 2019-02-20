#include "stdio.h"
#include "stdlib.h"
#define Maxsize 20

typedef char ElemType;

typedef struct 
{
	ElemType data[Maxsize];
	int top;
}SqStack;

//����ȫ������
void InitStack(SqStack * &s);//��ʼ��ջ
void DestroyStack(SqStack * &s);//����ջ
bool StackEmpty(SqStack * &s);//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack * &s,ElemType e);//��ջ
bool Pop(SqStack * &s,ElemType &e);//��ջ
int StackLength(SqStack *s);//����ջ�ĳ���
void DispStack(SqStack *s);//���ջ����ջ�׵�Ԫ��
void StackOrder(SqStack *s);//�����ջ˳��

void InitStack(SqStack * &s)//��ʼ��ջ
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

void DestroyStack(SqStack * &s)//����ջ
{
	free(s);
}

bool StackEmpty(SqStack * &s)//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1); 
}	

bool Push(SqStack * &s,ElemType e)//��ջ
{
	if(s->top==Maxsize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Pop(SqStack * &s,ElemType &e)//��ջ
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack * &s,ElemType &e)//ȡջ��Ԫ��
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}

int StackLength(SqStack *s)//����ջ�ĳ���
{
	return (s->top)+1;
}

void DispStack(SqStack *s)//���ջ����ջ�׵�Ԫ��
{
	int i;
	for(i=s->top;i>-1;i--)
	{
		printf("%c ",s->data[i]);
	}
	printf("\n");
}

void StackOrder(SqStack *s)//�����ջ˳��
{
	printf("%d ",s->top+1);
}

int main(int argc,char *argv[])
{
	SqStack *s;
	ElemType e;
	InitStack(s);
	StackEmpty(s)?printf("��ջ\n"):printf("���ǿ�ջ\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	StackEmpty(s)?printf("��ջ\n"):printf("���ǿ�ջ\n");
	printf("StackLength :%d\n",StackLength(s));
	DispStack(s);
	StackOrder(s);
	Pop(s,e);
	StackOrder(s);
	Pop(s,e);
	StackOrder(s);
	Pop(s,e);
	StackOrder(s);
	Pop(s,e);
	StackOrder(s);
	Pop(s,e);
	putchar('\n');
	StackEmpty(s)?printf("��ջ\n"):printf("���ǿ�ջ\n");
	DestroyStack(s);
	return 0;
}	
