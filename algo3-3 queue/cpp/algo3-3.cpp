#include "stdio.h"
#include "stdlib.h"
#define Maxsize 6
typedef char ElemType;

typedef struct 
{
	ElemType data[Maxsize];
	int front,rear;
}SqQueue;


//����ȫ������
void InitQueue(SqQueue * &q);//��ʼ������
void DestroyQueue(SqQueue * &q);//���ٶ���
bool QueueEmpty(SqQueue *q);//�ж϶����Ƿ�Ϊ��
bool enQueue(SqQueue * &q,ElemType e);//������
bool deQueue(SqQueue * &q,ElemType e);//������
int QueueLength(SqQueue * &q );//������еĳ���
void OutOrderQueue(SqQueue * &q);//���ض��е�����

void InitQueue(SqQueue * &q)//��ʼ������
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=-1; // front ָ����� rearָ���β
}

void DestroyQueue(SqQueue * &q)//���ٶ���
{
	free(q);
}

bool QueueEmpty(SqQueue *q)//�ж϶����Ƿ�Ϊ��
{
	return (q->front==q->rear);
}

bool enQueue(SqQueue * &q,ElemType e)//������
{
	if(q->rear==Maxsize-1)
		return false;
	q->rear++;
	q->data[q->rear]=e;
	return true;
}

bool deQueue(SqQueue * &q,ElemType e)//������
{
	if(q->front==q->rear)
		return false;
	q->front++;
	e=q->data[q->front];
	return true;
}

int QueueLength(SqQueue * &q )//������еĳ���
{
	return (q->rear+1);
}

void OutOrderQueue(SqQueue * &q)//���ض��е�����
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
