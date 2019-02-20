#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
}LiStack;

//声明全部函数
void InitStack(LiStack * &s);//初始化栈
void Destory(LiStack * &s);//销毁栈
bool StackEmpty(LiStack *s);//判断链栈是否为空
void Push (LiStack * &s,ElemType e);//进栈
bool Pop(LiStack * &s,ElemType e);//出栈
bool GetTop(LiStack *s,ElemType &e);//取栈顶元素
int StackLength(LiStack *s);//栈的长度
void DispStack(LiStack *s);//输出链栈的元素
void OrderStack(LiStack *s);//输出链栈的序列

void InitStack(LiStack * &s)//初始化链栈
{
	s=(LiStack *)malloc(sizeof(LiStack));
	s->next=NULL;
}

void Destory(LiStack * &s)//销毁链栈
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

bool StackEmpty(LiStack *s)//判断链栈是否为空
{
	return (s->next==NULL);
}
void Push (LiStack * &s,ElemType e)//进栈
{
	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;
	p->next=s->next;
	s->next=p;
}

bool Pop(LiStack * &s,ElemType e)//出栈
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

bool GetTop(LiStack *s,ElemType &e)//取栈顶元素
{
	if(s->next==NULL)
		return false;
	e=s->next->data;
	return true;
}

int StackLength(LiStack *s)//返回栈的长度
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

void DispStack(LiStack *s)//输出链栈的元素
{
	s=s->next;
	while(s!=NULL)
	{
		printf("%c ",s->data);
		s=s->next;
	}
	putchar('\n');
}

void OrderStack(LiStack *s)//输出链栈的序列
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
