#include "stdio.h"
#define Maxsize 30

typedef struct 
{
	char data[Maxsize];
	int length;
}SqString;

//����ȫ������
void StaAssign(SqString &s,char cstr[]);//�ַ���������ֵ����s
void StrCopy(SqString &s,SqString &t);//����t��ֵ����s
bool StrEqual(SqString &s,SqString &t);//�жϴ�s��t���
int StrLength(SqString &s);//���ش�s�ĳ���
SqString Concat(SqString &s,SqString &t);//�����ӣ�����һ���ɴ�s�ʹ�t���ɵ��´�
SqString SubStr(SqString s,int i,int j);//�ڴ�s��ȡ�� ��i��ʼj��Ԫ����ɵ��ַ���
SqString InsStr(SqString s1,SqString s2,int i);//����s2���뵽��s1�ĵ�i��1��i��StrLength��s��+1��
SqString RepStr(SqString s,int i,int j,SqString t);//�ڴ�s�У�����i��i��StrLength��s�������ַ���ʼ��j���ַ����ַ����ɵ��Ӵ��ô�t�滻�������´�


void StaAssign(SqString &s,char cstr[])//�ַ���������ֵ����s
{
	int i=-1;

	while(cstr[i]!='\0')//&& i< Maxsize
	{
		s.data[i]=cstr[i];
		++i;
	}

//	while( (s.data[i]=cstr[i++] ) != '\0');
	s.length=i;
}

void StrCopy(SqString &s,SqString &t)//����t��ֵ����s
{
	int i=0;
	while(s.data[i]=t.data[i++]!='0');//&& i< Maxsize
	s.length=t.length;
}

bool StrEqual(SqString &s,SqString &t)//�жϴ�s��t���
{
	bool same = true;
	int i;
	if(s.length!=t.length)
		return false;
	else 
		for(i=0;i<s.length;i++)
		{
			if(s.data[i]!=t.data[i])
			{
			same=false;
			break;
			}
		}
		return same;
}

int StrLength(SqString &s)//���ش�s�ĳ���
{
	return s.length;
}

SqString Concat(SqString &s,SqString &t)//�����ӣ�����һ���ɴ�s�ʹ�t���ɵ��´�
{
	SqString str;
	str.length=0;
	int i=0;
	str.length=s.length+t.length;

	for(i=0;i<s.length;i++)
		str.data[i]=s.data[i];
	for(i=0;i<t.length;i++)
		str.data[s.length+i]=t.data[i];
	return str;
} 

SqString SubStr(SqString s,int i,int j)//�ڴ�s��ȡ�� ��i��ʼj��Ԫ����ɵ��ַ���
{
	SqString str;
	int m;

	if(i>s.length || i<=0 || j<0 || i+j-1>s.length)
		return str;
	for(m=i-1;m<j;m++)
		str.data[m-i+1]=s.data[m];
	str.length=j;
	return str;
}

SqString InsStr(SqString s1,SqString s2,int i)//����s2���뵽��s1�ĵ�i��1��i��StrLength��s��+1��
{
	int j;
	SqString Str;
	Str.length=0;
	if(i<0 && i>=s1.length-1)
		return Str;

	for(j=0;j<i-1;j++)
		Str.data[j]=s1.data[j];
	for(j=0;j<s2.length;j++)
		Str.data[j+i-1]=s2.data[j];
	for(j=i-1;j<s1.length;j++)
		Str.data[s2.length+j]=s1.data[j];
	Str.length=s1.length+s2.length;
	return Str;
}

SqString DelStr(SqString s,int i,int j)//�Ӵ�s��ɾ����i��1��i��StrLength��s��������Ϊj���Ӵ��������ز����� �´�
{
	int k;
	SqString Str;
	Str.length=0;
	if(i<=0 || i>s.length || i+j>s.length+1)
		return Str;
	for(k=0;k<i-1;k++)
	{	
		Str.data[k]=s.data[k];
	}
	for(k=i+j-1;k<s.length;k++)
	{
		Str.data[k-j]=s.data[k];
	}
	Str.length=s.length-j;
	return Str;
}
SqString RepStr(SqString s,int i,int j,SqString t)//�ڴ�s�У�����i��i��StrLength��s�������ַ���ʼ��j���ַ����ַ����ɵ��Ӵ��ô�t�滻�������´�
{
	int k;
	SqString Str;
	Str.length=0;
	if(i<=0 || i > s.length || i+j-1>s.length)
		return Str;
	for(k=0;k<i-1;k++)
		Str.data[k]=s.data[k];

	for(k=0;k<t.length;k++)
		Str.data[i+k-1]=t.data[k];

	for(k=i+j-1;k<s.length;k++)
		Str.data[t.length+k-1]=s.data[k];

	Str.length=s.length-j+t.length;
	return Str;
}

void DispStr(SqString s)//�����s���е�ֵ
{
	int i;
	if(s.length>0)
	{
		for(i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}

int main(int argc,char *argv[])
{
	SqString s;
	SqString s1;
	SqString s2;
	char c[Maxsize]="abcdefghefghijklmn";
	char c1[Maxsize]="xyz";
	StaAssign(s,c);
	StaAssign(s1,c1);
	DispStr(s);
	printf("SrtLength��%d\n",StrLength(s));
	s2=InsStr(s,s1,9);
	DispStr(s2);
	return 0;
}