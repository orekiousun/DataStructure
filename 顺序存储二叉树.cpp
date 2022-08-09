#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
struct SeqBiTree  
{
	char data[Maxsize];
	int biTreeNum;
};
void CreatBiTree(SeqBiTree *tree)
{
	tree->biTreeNum=0;
	printf("����������Ԫ��:");
	for(int i=1;;i++)
	{
		scanf("%c",&tree->data[i]);
		if(tree->data[i]=='0')
		{
			break;
		}
		tree->biTreeNum++;
	} 
	printf("biTreeNum��ֵΪ��%d\n",tree->biTreeNum);
}
void PreOrder(SeqBiTree *tree,int n)
{
	if(n>tree->biTreeNum)
	{
		return;
	}
	else
	{
		if(tree->data[n]=='#')
		{
		
		}
		else
		{
			printf("%c ",tree->data[n]);
		} 
		PreOrder(tree,2*n);
		PreOrder(tree,(2*n)+1);
	}
}
void InOrder(SeqBiTree *tree,int n)
{
	if(n>tree->biTreeNum)
	{
		return;
	}
	else
	{
		InOrder(tree,2*n);
		if(tree->data[n]=='#')
		{
		
		}
		else
		{
			printf("%c ",tree->data[n]);
		} 
		InOrder(tree,(2*n)+1);
	}
}
void PostOrder(SeqBiTree *tree,int n)
{
	if(n>tree->biTreeNum)
	{
		return;
	}
	else
	{
		PostOrder(tree,2*n);
		PostOrder(tree,(2*n)+1);
		if(tree->data[n]=='#')
		{
		
		}
		else
		{
			printf("%c ",tree->data[n]);
		} 
	}
}
void LevelOrder(SeqBiTree *tree)
{
	for(int i=1;i<=tree->biTreeNum;i++)
	{
		if(tree->data[i]=='#')
		{
		
		}
		else
		{
			printf("%c ",tree->data[i]);
		} 
	} 
}
int main()
{
	SeqBiTree tree;
	CreatBiTree(&tree);
	printf("ǰ�������");
	PreOrder(&tree,1); 
	printf("\n");
	printf("���������");
	InOrder(&tree,1);
	printf("\n");
	printf("���������");
	PostOrder(&tree,1);
	printf("\n");
	printf("���������");
	LevelOrder(&tree);
	printf("\n");
	return 0;
}
