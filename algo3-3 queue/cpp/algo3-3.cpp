#include "stdio.h"
#include "stdlib.h"
#define Maxsize 6
typedef char ElemType;

typedef struct 
{
	ElemType data[Maxsize];
	int front,rear;
}SqQueue;


//声明全部函数
void InitQueue(SqQueue * &q);//初始化队列
void DestroyQueue(SqQueue * &q);//销毁队列
bool QueueEmpty(SqQueue *q);//判断队列是否为空
bool enQueue(SqQueue * &q,ElemType e);//进队列
bool deQueue(SqQueue * &q,ElemType e);//出队列
int QueueLength(SqQueue * &q );//输出队列的长度
void OutOrderQueue(SqQueue * &q);//返回队列的序列

void InitQueue(SqQueue * &q)//初始化队列
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=-1; // front 指向队首 rear指向队尾
}

void DestroyQueue(SqQueue * &q)//销毁队列
{
	free(q);
}

bool QueueEmpty(SqQueue *q)//判断队列是否为空
{
	return (q->front==q->rear);
}

bool enQueue(SqQueue * &q,ElemType e)//进队列
{
	if(q->rear==Maxsize-1)
		return false;
	q->rear++;
	q->data[q->rear]=e;
	return true;
}

bool deQueue(SqQueue * &q,ElemType e)//出队列
{
	if(q->front==q->rear)
		return false;
	q->front++;
	e=q->data[q->front];
	return true;
}

int QueueLength(SqQueue * &q )//输出队列的长度
{
	return (q->rear+1);
}

void OutOrderQueue(SqQueue * &q)//返回队列的序列
{	int i;
	for(i=1;i<=(q->rear-q->front);i++)
	{
		printf("%d ",i);
	}
	printf("\n");
}
int main(int argc,char *argv[])
{
	SqQueue *q;
	ElemType e;
	InitQueue(q);
	QueueEmpty(q)?printf("QueueEmpty\n"):printf("Not An QueueEmpty\n");
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	printf("'abc' input Queue:\n");
	QueueEmpty(q)?printf("QueueEmpty\n"):printf("Not An QueueEmpty\n");
	printf("QueueLength: %d\n",QueueLength(q));
	OutOrderQueue(q);
	DestroyQueue(q);
	return 0;
}
