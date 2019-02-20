#include "stdio.h"
#include "stdlib.h"
#define MaxSize 50

typedef char ElemType;

//定义线性表
typedef struct 
{
	ElemType date[MaxSize];
	int length;
}SqList;

//声明所有函数
void initList(SqList * &L);//初始化线性表
void DestroyList(SqList * &L);//销毁线性表
bool ListEmpty(SqList *L); //判断是否为空表 return 1为空 return 0不是空表
int ListLength(SqList *L);//返回线性表长度
void CreateList(SqList * &L,ElemType a[],int n); //由数组a中的数值确定线性表的值
void DispList(SqList *L);//输出线性表中所有元素的值
bool GetElem(SqList *L,int i,ElemType &e); //用e返回第i个元素的值 
int LocateElem(SqList *L,ElemType e);//返回和e匹配元素的 下标/位置
bool ListDelete(SqList *L,int i,ElemType &e);//删除第i个元素 用e保存第i个元素的值
void Delnodel(SqList *L,ElemType x); //删除和x 匹配的值
bool ListInsert(SqList * &L,int i,ElemType e);  //在第i个元素位置上插入字符变量e的内容


void initList(SqList * &L) //初始化线性表
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length=0;
}

void DestroyList(SqList * &L) //销毁线性表
{
	free(L);
}

bool ListEmpty(SqList *L) //判断是否为空表 return 1为空 return 0不是空表
{
	return (L->length==0);
}

int ListLength(SqList *L)//返回线性表长度
{
	return (L->length);
}

void CreateList(SqList * &L,ElemType a[],int n) //由数组a中的数值确定线性表的值
{
	int i;
	L=(SqList *)malloc(sizeof(SqList));
	for(i=0;i<n;i++)
	{
		L->date[i]=a[i];
		
	}
	L->length=n;
}

void DispList(SqList *L)//输出线性表中的值
{	
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("%c ",L->date[i]);
	}
	printf("\n");
}

bool GetElem(SqList *L,int i,ElemType &e) //用e返回第i个元素的值 
{
	if(i<1 || i > L->length)
		return false;
	e=L->date[i-1];
	return true;
}

int LocateElem(SqList *L,ElemType e) //返回和e匹配元素的 下标/位置
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
bool ListDelete(SqList *L,int i,ElemType &e)//删除第i个元素 用e保存第i个元素的值
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

void Delnodel(SqList *L,ElemType x) //删除和x 匹配的值
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
void Delnodel2(SqList *L,ElemType x) //删除和x匹配的值 第二种方法
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

 bool ListInsert(SqList * &L,int i,ElemType e)  //在第i个元素位置上插入字符变量e的内容
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
	CreateList(p,e,7); //用字符数组a给线性表赋7个初始值 
	printf("线性表的元素内容：\n");
	DispList(p);  //输出线性表
	(ListEmpty(p))?printf("此线性表是空表\n"):printf("此线性表不是空表\n");
	printf("请输入要输出元素的位置：");
	
	scanf("%d",&i);
	GetElem(p,i,x);
	printf("%c\n",x);
	getchar();
	
	printf("请输入要返回下标的字符：");
	scanf("%c",&x);
	printf("\n%d\n",LocateElem(p,x));
	
	printf("请输入你要插入字符的位置：");
	scanf("%d",&i);
	getchar();
	printf("请输入你要插入的字符：");
	scanf("%c",&x);
	ListInsert(p,i,x);
	DispList(p);

	printf("请输入你要删除的元素位置：");
	scanf("%d",&i);
	ListDelete(p,i,x);
	DispList(p);
	DestroyList(p);
	return 0;
}