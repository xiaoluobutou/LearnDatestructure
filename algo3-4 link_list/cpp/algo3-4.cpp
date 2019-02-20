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

//�������к���
void InitQueue(LiQueue * &q);//��ʼ��������
void DestroyQueue(LiQueue * &q);//����������
bool QueueEmpty(LiQueue * &q);//�ж϶����Ƿ�Ϊ��
void enQueue(LiQueue * &q,ElemType e);//������
bool deQueue(LiQueue * &q,ElemType &e);//������
int QueueLength(LiQueue *q);//������еĳ���

void InitQueue(LiQueue * &q)//��ʼ��������
{
	q=(LiQueue *)malloc(LEN);
	q->front=q->rear=NULL;
}

void DestroyQueue(LiQueue * &q)//����������
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

bool QueueEmpty(LiQueue * &q)//�ж϶����Ƿ�Ϊ��
{
	return (q->rear==NULL);
}

void enQueue(LiQueue * &q,ElemType e)//������
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

bool deQueue(LiQueue * &q,ElemType &e)//������
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

int QueueLength(LiQueue *q)//������еĳ���
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