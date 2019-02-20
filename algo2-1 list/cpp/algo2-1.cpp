#include "stdio.h"
#include "stdlib.h"
#define MaxSize 50

typedef char ElemType;

//�������Ա�
typedef struct 
{
	ElemType date[MaxSize];
	int length;
}SqList;

//�������к���
void initList(SqList * &L);//��ʼ�����Ա�
void DestroyList(SqList * &L);//�������Ա�
bool ListEmpty(SqList *L); //�ж��Ƿ�Ϊ�ձ� return 1Ϊ�� return 0���ǿձ�
int ListLength(SqList *L);//�������Ա���
void CreateList(SqList * &L,ElemType a[],int n); //������a�е���ֵȷ�����Ա��ֵ
void DispList(SqList *L);//������Ա�������Ԫ�ص�ֵ
bool GetElem(SqList *L,int i,ElemType &e); //��e���ص�i��Ԫ�ص�ֵ 
int LocateElem(SqList *L,ElemType e);//���غ�eƥ��Ԫ�ص� �±�/λ��
bool ListDelete(SqList *L,int i,ElemType &e);//ɾ����i��Ԫ�� ��e�����i��Ԫ�ص�ֵ
void Delnodel(SqList *L,ElemType x); //ɾ����x ƥ���ֵ
bool ListInsert(SqList * &L,int i,ElemType e);  //�ڵ�i��Ԫ��λ���ϲ����ַ�����e������


void initList(SqList * &L) //��ʼ�����Ա�
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length=0;
}

void DestroyList(SqList * &L) //�������Ա�
{
	free(L);
}

bool ListEmpty(SqList *L) //�ж��Ƿ�Ϊ�ձ� return 1Ϊ�� return 0���ǿձ�
{
	return (L->length==0);
}

int ListLength(SqList *L)//�������Ա���
{
	return (L->length);
}

void CreateList(SqList * &L,ElemType a[],int n) //������a�е���ֵȷ�����Ա��ֵ
{
	int i;
	L=(SqList *)malloc(sizeof(SqList));
	for(i=0;i<n;i++)
	{
		L->date[i]=a[i];
		
	}
	L->length=n;
}

void DispList(SqList *L)//������Ա��е�ֵ
{	
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("%c ",L->date[i]);
	}
	printf("\n");
}

bool GetElem(SqList *L,int i,ElemType &e) //��e���ص�i��Ԫ�ص�ֵ 
{
	if(i<1 || i > L->length)
		return false;
	e=L->date[i-1];
	return true;
}

int LocateElem(SqList *L,ElemType e) //���غ�eƥ��Ԫ�ص� �±�/λ��
{
	int i;
	for(i=0;i<L->length;i++)
	{
		if(L->date[i] == e)
			break;
	}
	if(L->length < i)
		return 0;
	else 
		return i+1;
}
bool ListDelete(SqList *L,int i,ElemType &e)//ɾ����i��Ԫ�� ��e�����i��Ԫ�ص�ֵ
{
	int j;
	if(i < 1 || i > L->length)
		return false;
	i--;
	e=L->date[i];
	for(j=i;j<L->length-1;j++)
	{
		L->date[j]=L->date[j+1];
	}
	L->length--;
	return true;
}

void Delnodel(SqList *L,ElemType x) //ɾ����x ƥ���ֵ
{
	int k=0;
	int i;

	for(i=0;i<L->length;i++)
	{
		if(L->date[i] != x)
		{	
			L->date[k] =L->date[i];
			k++;
		}	
	}
	L->length=k;
}


/*
void Delnodel2(SqList *L,ElemType x) //ɾ����xƥ���ֵ �ڶ��ַ���
{
	int i,k;
	i=k=0;
	while(i<L->length)
	{	
		if(L->date[i]==x)
			K++;
		else 
			L->date[i-k]=L->date[i];
		++i;
	}
	L->length-=k;
}
*/

 bool ListInsert(SqList * &L,int i,ElemType e)  //�ڵ�i��Ԫ��λ���ϲ����ַ�����e������
 {
	int j;
	if(i<1 ||i>L->length+1)
		return false;
	i--;
	for(j=L->length;j>i;j--)
	{
		L->date[j]=L->date[j-1];
	}
	L->date[i]=e;
	L->length++;
	return true;
 }
int main(int argc,char *argv[])
{	ElemType e[MaxSize]="abcdefg";
	ElemType x;
	int i;
	SqList *p;

	initList(p);
	CreateList(p,e,7); //���ַ�����a�����Ա�7����ʼֵ 
	printf("���Ա��Ԫ�����ݣ�\n");
	DispList(p);  //������Ա�
	(ListEmpty(p))?printf("�����Ա��ǿձ�\n"):printf("�����Ա��ǿձ�\n");
	printf("������Ҫ���Ԫ�ص�λ�ã�");
	
	scanf("%d",&i);
	GetElem(p,i,x);
	printf("%c\n",x);
	getchar();
	
	printf("������Ҫ�����±���ַ���");
	scanf("%c",&x);
	printf("\n%d\n",LocateElem(p,x));
	
	printf("��������Ҫ�����ַ���λ�ã�");
	scanf("%d",&i);
	getchar();
	printf("��������Ҫ������ַ���");
	scanf("%c",&x);
	ListInsert(p,i,x);
	DispList(p);

	printf("��������Ҫɾ����Ԫ��λ�ã�");
	scanf("%d",&i);
	ListDelete(p,i,x);
	DispList(p);
	DestroyList(p);
	return 0;
}