#include "stdio.h"
#include "stdlib.h"
#define Maxsize 20

typedef char ElemType;

typedef struct 
{
	ElemType data[Maxsize];
	int top;
}SqStack;

//声明全部函数
void InitStack(SqStack * &s);//初始化栈
void DestroyStack(SqStack * &s);//销毁栈
bool StackEmpty(SqStack * &s);//判断栈是否为空
bool Push(SqStack * &s,ElemType e);//进栈
bool Pop(SqStack * &s,ElemType &e);//出栈
int StackLength(SqStack *s);//返回栈的长度
void DispStack(SqStack *s);//输出栈顶到栈底的元素
void StackOrder(SqStack *s);//输出出栈顺序

void InitStack(SqStack * &s)//初始化栈
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

void DestroyStack(SqStack * &s)//销毁栈
{
	free(s);
}

bool StackEmpty(SqStack * &s)//判断栈是否为空
{
	return(s->top==-1); 
}	

bool Push(SqStack * &s,ElemType e)//进栈
{
	if(s->top==Maxsize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Pop(SqStack * &s,ElemType &e)//出栈
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack * &s,ElemType &e)//取栈顶元素
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}

int StackLength(SqStack *s)//返回栈的长度
{
	return (s->top)+1;
}

void DispStack(SqStack *s)//输出栈顶到栈底的元素
{
	int i;
	for(i=s->top;i>-1;i--)
	{
		printf("%c ",s->data[i]);
	}
	printf("\n");
}

void StackOrder(SqStack *s)//输出出栈顺序
{
	printf("%d ",s->top+1);
}

int main(int argc,char *argv[])
{
	SqStack *s;
	ElemType e;
	InitStack(s);
	StackEmpty(s)?printf("空栈\n"):printf("不是空栈\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	StackEmpty(s)?printf("空栈\n"):printf("不是空栈\n");
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
	StackEmpty(s)?printf("空栈\n"):printf("不是空栈\n");
	DestroyStack(s);
	return 0;
}	
