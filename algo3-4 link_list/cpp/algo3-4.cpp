#include "stdio.h"
#include "stdlib.h"
#define Maxsize 4
#define LEN sizeof(LiQueue)
typedef char ElemType;

typedef struct qnode
{
	ElemType data;
	struct qnode *next;
}QNode;

typedef struct 
{
	QNode *front;
	QNode *rear;
}LiQueue;

//声明所有函数
void InitQueue(LiQueue * &q);//初始化链队列
void DestroyQueue(LiQueue * &q);//销毁链队列
bool QueueEmpty(LiQueue * &q);//判断队列是否为空
void enQueue(LiQueue * &q,ElemType e);//进队列
bool deQueue(LiQueue * &q,ElemType &e);//出队列
int QueueLength(LiQueue *q);//输出队列的长度

void InitQueue(LiQueue * &q)//初始化链队列
{
	q=(LiQueue *)malloc(LEN);
	q->front=q->rear=NULL;
}

void DestroyQueue(LiQueue * &q)//销毁链队列
{
	QNode *p=q->front,*r;
	if(p!=NULL)
	{
		r=p->next;
		while(r!=NULL)
		{
			free(p);
			p=r;
			r=p->next;
		}
		free(p);
		free(q);
	}
}

bool QueueEmpty(LiQueue * &q)//判断队列是否为空
{
	return (q->rear==NULL);
}

void enQueue(LiQueue * &q,ElemType e)//进队列
{
	QNode *p;
	p=(QNode *)malloc(LEN);
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL)
		q->front=q->rear=p;
	else 
	{
		q->rear->next=p;
		q->rear=p;
	}
}

bool deQueue(LiQueue * &q,ElemType &e)//出队列
{
	QNode *t;
	if(q->rear==NULL)
		return false;
	t=q->front;
	if(q->front==q->rear)
		q->front=q->rear=NULL;
	else
		q->front=q->front->next;
	e=t->data;
	free(t);
	return true;
}

int QueueLength(LiQueue *q)//输出队列的长度
{
	int n=0;
	while(q->front!=NULL)
	{
		++n;
		q->front=q->front->next;
	}	
	return n;
}
int main()
{
	LiQueue *q;
	ElemType e;
	InitQueue (q);
	QueueEmpty(q)?printf("NULL\n"):printf("NOT NULL\n");
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	QueueEmpty(q)?printf("NULL\n"):printf("NOT NULL\n");
	deQueue(q,e);
	printf("%c ",e);
	deQueue(q,e);
	printf("%c ",e);
	deQueue(q,e);
	printf("%c \n",e);
	printf("LiQueueLength :%d\n",QueueLength(q));
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("LiQueueLength :%d\n",QueueLength(q));
	DestroyQueue(q);
	return 0;
}