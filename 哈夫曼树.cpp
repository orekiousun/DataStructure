#include<stdio.h>
#include<stdlib.h>
struct Huffman
{
	int weight;
	int parent,lchild,rchild;
};
void CreatHuffmanTree(Huffman tree[],int a[],int n)
{
	int k,i1,i2;
	for(int i=0;i<2*n-1;i++)
	{
		tree[i].parent=-1;
		tree[i].lchild=-1;
		tree[i].rchild=-1;
	}
	for(int i=0;i<n;i++)
	{
		tree[i].weight=a[i];
	}
	for(k=n;k<2*n-1;k++)
	{
		
		int temp1=1000000,temp2=1000000;
		
		for(int i=0;i<k;i++)
		{
			if(tree[i].parent==-1)
			{
				if(tree[i].weight<=temp1)
				{
					temp1=tree[i].weight;
					i1=i;
				}
			}
			else
			{
			}
		}
		for(int i=0;i<k;i++)
		{
			if(tree[i].parent==-1)
			{
				if(i==i1)
				{
				}
				else
				{
					if(tree[i].weight<=temp2)
					{
						temp2=tree[i].weight;
						i2=i;
					}
				}
			}
			else
			{
			}
		}
		tree[k].weight=tree[i1].weight+tree[i2].weight;
		tree[i1].parent=k;tree[i2].parent=k;
		tree[k].lchild=i1;tree[k].rchild=i2;
	}

	for(int i=0;i<2*n-1;i++)
	{
		printf("%d ",tree[i].weight);
	}
}
int main()
{
	Huffman tree[100];
	int a[9]={1,2,3,4,5,6,7,8,9};
	CreatHuffmanTree(tree,a,9);
	return 0;
}
