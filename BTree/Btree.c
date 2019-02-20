#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef char ElemType;
#define MaxSize 100

typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BT;


BT *CreateBTNode(char *str)
///创建二叉树
{
	BT *st[MaxSize], *p = NULL, *b = NULL;
	int top = -1, k, j = 0;
	ElemType ch;
	ch =  str[j];

	while(ch != '\0')
	{
		switch(ch)
		{
			case '(': top++; st[top]=p; k=1; break;
			case ')': top--; break;
			case ',': k = 2; break;
			
			default : 
				p = (BT*)malloc(sizeof(BT));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if(b==NULL)
					b=p;
				else 
				{
					switch(k)
					{
						case 1: st[top]->lchild = p; break;
						case 2: st[top]->rchild = p; break;
					}
				}
		}
		j++; ch = str[j];
	}

	return (b);
}



BT *LchildNode(BT *p)
///返回左孩子节点
{
	return p->lchild;
}

BT *RchildNode(BT *p)
///返回右孩子节点
{
	return p->rchild;
}

BT *findNote(BT *b,ElemType data) 
///查找节点
{
	BT *p;
	if(b == NULL)
		return NULL;
	else if(b->data == data)
		return b;
	else 
	{
		p = findNote(b->lchild,data);
		if(b != NULL)
			return p;
		else 
		{
			return findNote(b->rchild,data);
		}
	}
	
}

int BTNodeHeight(BT *b)
///返回树的高度
{
	int lChildH,rChildH;
	if(b == NULL)return 0;
	else 
	{
		lChildH = BTNodeHeight(b->lchild);
		rChildH = BTNodeHeight(b->rchild);
		return (lChildH > rChildH ? (lChildH + 1):(rChildH +1));
	}
}

void DispBTNode(BT *b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild !=NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if(b->rchild !=NULL)printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}


void PreOrder(BT *b)
///先序遍历的递归算法
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BT *b)
///中序遍历的递归算法
{
	if(b!=NULL)
	{
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}

void PostOrder(BT *b)
///后续遍历的递归算法
{
	if(b !=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c",b->data);
	}
}

void PerOrder2()
{

}
void InOrder2(BT *b)
///非递归中序遍历
{
	BT *st[MaxSize], *p;
	int top = -1;
	if(b != NULL)
	{
		p = b;
		while(top > -1 || p!=NULL)
		{
			while(p != NULL)
			{
				top++;
				st[top]=p;
				p=p->lchild;
			}

			if(top > -1)
			{
				p = st[top];
				top--;
				printf("%c",p->data);
				p=p->rchild;
			}
		}
		printf("\n");
		
	}

}
int main()
{
	int i=0;
	int j=0;
	BT *b;
	ElemType *ch= "A(B(E,F),C(G(J))";
	b = CreateBTNode(ch);
	printf("元素A的地址：0x00%x\n",findNote(b,'J'));
	printf("树的度为：%d\n",BTNodeHeight(b));
	DispBTNode(b);
		printf("\n");
	PreOrder(b);
		printf("\n");
	InOrder(b);
		printf("\n");
	PostOrder(b);
		printf("\n");
	return 0;
}