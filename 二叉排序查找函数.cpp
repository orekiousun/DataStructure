#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
	int data;
    node *lchild,*rchild;
};
node* InitBST(node *root)
{
	root=NULL;
	return root;
}
void print(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root!=NULL)
	{
		printf("%d  \n%p  %p\n",root->data,root->lchild,root->rchild);
		print(root->lchild);
		print(root->rchild);
	}
}
node *InsertBST(node *root,int x)
{
	if(root==NULL)
	{
		node *s;
		s=(node*)malloc(sizeof(node));
		s->data=x;
		s->lchild=NULL;
		s->rchild=NULL;
		root=s;
		return root;
	}
	else if(root->data>x)
	{
		root->lchild=InsertBST(root->lchild,x);
		return root;
	}	
	else
	{
		root->rchild=InsertBST(root->rchild,x);
		return root;
	}
} 
node *CreatBST(node *root,int r[],int n)
{
	for(int i=0;i<n;i++)
	{
		root=InsertBST(root,r[i]);
	}
	return root;
}
void DeleteBST(node *p,node *f)
{
	if(p->lchild==NULL&&p->rchild==NULL&&f->lchild==p) 
	{
		f->lchild=NULL;
		free(p);
		return;
	}//pΪҶ�ӽ����pΪf������
	else if(p->lchild==NULL&&p->rchild==NULL&&f->rchild==p)
	{
		f->rchild=NULL;
		free(p);
		return;
	}//pΪҶ�ӽ����pΪf������
	else if(p->rchild==NULL&&p->lchild!=NULL&&f->lchild==p)
	{
		f->lchild=p->lchild;
		free(p);
		return;
	}//pֻ����������pΪf������ 
	else if(p->rchild==NULL&&p->lchild!=NULL&&f->rchild==p)
	{
		f->rchild=p->lchild;
		free(p);
		return;
	}//pֻ����������pΪf������ 
	else if(p->rchild!=NULL&&p->lchild==NULL&&f->lchild==p)
	{
		f->lchild=p->rchild;
		free(p);
		return;
	} //pֻ����������pΪf������ 
	else if(p->rchild!=NULL&&p->lchild==NULL&&f->rchild==p)
	{
		f->rchild=p->rchild;
		free(p);
		return;
	} //pֻ����������pΪf������
	else if(p->lchild!=NULL&&p->rchild!=NULL)
	{
		node *parent=p,*s=p->lchild;
		while(s->rchild!=NULL)
		{
			parent=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(s->lchild!=NULL)
		{
			parent->lchild=s->lchild;
		}
		else
		{
			parent->lchild==NULL;
		}
		free(s);
	}//p������������pΪf������(�����������������½��)
	//ֱ�ӽ�p��ָ���ֵ��Ϊs��ָ�뱾���� 
}
int SearchBST(node *root,int k)
{
	if(root==NULL) return 0; 
	if(root->data==k)
	{
		return 1;
	}
//	printf("**%p\n",root);	
//	if(root->data>k)
//	{
//		if(root->lchild==NULL) return 0; 
//	}
//	if(root->data<k)
//	{
//		if(root->rchild==NULL) return 0; 
//	}
	if(root->data>k) return SearchBST(root->lchild,k);
	else return SearchBST(root->rchild,k);
}
int level=1;
void GetLevel(node *root,int k) 
{
	if(k==root->data)
	{
		return level;
	}
	else
	{
		if(k<root->data)
		{
			level++;
			GetLevel(root->lchild,k)
		}
		else
		{
			level++;
			Getlevel(root->rchild,k)
		}
	}
}

int main()
{
	printf("������������Ԫ�ظ���:\n");
	int n;
	scanf("%d",&n);
	int r[n];
	srand((int)time(0));
	for(int i=0;i<n;i++)
	{
		r[i]=rand()%101;
		printf("%d ",r[i]);
	}
	printf("\n");
	node *root;
	root=InitBST(root);
	root=CreatBST(root,r,n);
	printf("��������Ҫ���ҵ�ֵ��\n");
	int m;
	scanf("%d",&m);
	int p;
	p=SearchBST(root,m);
	if(p)
	{
		printf("���ҳɹ�\n"); 
	}
	else
	{
		printf("����ʧ��\n");
	}
	return 0;
} 









