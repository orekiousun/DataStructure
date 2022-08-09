#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define Maxsize 100
struct node
{
	char data;
	int level;
    node *lchild,*rchild;
};
void PreOrder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void InOrder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		InOrder(root->lchild);
		printf("%c",root->data);
		InOrder(root->rchild);
	}
}
void PostOrder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		printf("%c",root->data);
	}
}
void LevelOrder(node *root)
{
	node *q=NULL,*Q[Maxsize];
	int front=-1,rear=-1;
	if(root==NULL)
	{
		return;
	} 
	Q[++rear]=root;
	while(front!=rear)
	{
		q=Q[++front];
		printf("%c",q->data);
		if(q->lchild!=NULL) Q[++rear]=q->lchild;
		if(q->rchild!=NULL) Q[++rear]=q->rchild;
	}
}
node *CreatBiTree(node *root)
{
	char ch;
	cin>>ch;
	if(ch=='#')
	{
		root=NULL;
	}
	else
	{
		root=(node *)malloc(sizeof(node));
		root->data=ch;
		root->lchild=CreatBiTree(root->lchild);
		root->rchild=CreatBiTree(root->rchild);
	}
	return root;
}
void DestroyBiTree(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		DestroyBiTree(root->lchild);
		DestroyBiTree(root->rchild);
	}
}
int GetDepth(node *root)
{
	node *q=NULL,*Q[Maxsize];
	int front=-1,rear=-1;
	if(root==NULL)
	{
		return root->level;
	} 
	rear++;
	Q[rear]=root;
	Q[0]->level=1;
	while(front!=rear)
	{
		front++;
		q=Q[front];
		if(q->lchild!=NULL) 
		{
			rear++;
			Q[rear]=q->lchild;
			Q[rear]->level=Q[front]->level+1;
		}
		if(q->rchild!=NULL)
		{
			rear++;
			Q[rear]=q->rchild;
			Q[rear]->level=Q[front]->level+1;
		} 
	}
	return Q[front]->level;
}
int i=0;
void GetLeaf(node *root,int k)
{
	if(k==2)
	{
		if(root->lchild!=NULL)
		{
			i++;
		}
		if(root->rchild!=NULL)
		{
			i++;
		}
	}
	else
	{
		if(root->lchild!=NULL)
		{
			GetLeaf(root->lchild,k-1);
		}
		if(root->rchild!=NULL)
		{
			GetLeaf(root->rchild,k-1);
		}
	}
}  //һ�ö������Զ��������洢�����������k��k>1������Ҷ�ӽ��ĸ�����
void CopyTree(node *root,node *copy)
{
	node *s=(node *)malloc(sizeof(node));
	s->data=root->data;
	copy=s;
	if(root->lchild==NULL&&root->rchild==NULL)
	{
		return;
	}
	else
	{
		if(root->lchild!=NULL)
		{
			CopyTree(root->lchild,copy->lchild);
		}
		if(root->rchild!=NULL)
		{
			CopyTree(root->rchild,copy->rchild);
		}
	}
}
int main()
{
	node *root;
	root=CreatBiTree(root);
	GetDepth(root);
	printf("�����������Ϊ��%d\n",GetDepth(root));
	printf("ǰ�������");
	PreOrder(root); 
	printf("\n");
	printf("���������");
	InOrder(root);
	printf("\n");
	printf("���������");
	PostOrder(root);
	printf("\n");
	printf("���������");
	LevelOrder(root);
	printf("\n");
	return 0;
}
