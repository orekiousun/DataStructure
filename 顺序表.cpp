#include<stdio.h>
#include<stdlib.h>
#define  maxsize 100
int number[1000000];
typedef struct
{
	int *data;
	int length;
}Seqlist;
void InitList(Seqlist *l)
{
	l->length=0;
}
int Length(Seqlist *l)
{
	return l->length;
}
void Get(Seqlist *l,int i,int *ptr)
{
	if(i<=l->length&&i>0)
	{ 
		*ptr=l->data[i-1];
		printf("查找成功\n");
	}
	else
	{
		printf("数据错误，查找失败\n");
	}
} 
int Locate(Seqlist *l,int x)
{
	for(int i=0;i<l->length;i++)
	{
		if(l->data[i]==x)
		{
			return i+1;
		}
	}
}
void Insert(Seqlist *l,int i,int x)
{
	if(i<=l->length&&i>0)
	{
		for(int j=i;j<l->length;j++)
		{
			number[j]=l->data[j];
		}
		for(int k=l->length;k>=i-1;k--)
		{
			number[k+1]=number[k];	
		} 
		number[i-1]=x;
		free(l->data);
		l->data=(int *)malloc((l->length+1)*sizeof(int));
		l->length++;
		for(int k=0;k<l->length;k++)
		{
			l->data[k]=number[k];
		} 
		printf("插入成功\n");
		
	}
	else
	{
		printf("数据错误，插入失败\n");
	}
}

void Delete(Seqlist *l,int i)
{
	if(i<=l->length&&i>0)
	{
		for(int k=i-1;k<l->length-1;k++)
		{
			l->data[k]=l->data[k+1];	
		} 
		printf("删除成功\n");
		l->length--;
	}
	else
	{
		printf("数据错误，删除失败\n");
	}
}
int Empty(Seqlist *l)
{
	if(l->length==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
void Creatlist(Seqlist *l)
{
	int i=0;
	while(scanf("%d",&number[i])!=0)
	{
		i++;
	}
	l->length=i; 
	l->data=(int *)malloc((i)*sizeof(int));
	for(int m=0;m<=i;m++)
	{
		l->data[m]=number[m];
	}
	printf("创建成功\n");
}
void Printlist(Seqlist *l,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",l->data[i]);
	}
} 
int main()
{
	Seqlist l;
	Creatlist(&l);
	Insert(&l,3,666); 
	Printlist(&l,Length(&l));
} 

