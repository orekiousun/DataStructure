#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
    node *next;
};
void InitQueue(node *first)
{
	first->next=NULL;
	first->data=0;
}
void EnterQueue(node *first)
{
	int x;
	printf("�����������е�����");
	scanf("%d",&x);
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=first->next;
	first->next=p;
	first->data++;
}
void ExitQueue(node *first)
{
	if(first->data==0)
	{
		printf("������󣬳���ʧ��");
	}
	else
	{
		node *p=first;
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		node *s=p->next;
		printf("���ӵ���Ϊ��%d",s->data);
		p->next=s->next;
		free(s);
		first->data--;
	} 
}
void DestroyQueue(node *first)
{
	node *p=first;
	while(p->next!=NULL)
	{
		node *s;
		s=p->next;
		p->next=s->next;
		p=p->next;
		free(s);
	}
	first->data=0;
}
void ArrayEnter(node *first,int x)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=first->next;
	first->next=p;
	first->data++;
}
void func(node *first,int m)
{
	int sq[m];
	InitQueue(&first);
	int tag=0;
	
	for(int i=0;i<m;i++)
	{
				
	}
	for(int i=0;i<m;i++)
	{
		ArrayEnter(&first,sq[i]);
		tag++;	
	}	
} 
int main()
{
	node first;
	InitQueue(&first);
	EnterQueue(&first);
	EnterQueue(&first);
	EnterQueue(&first);
	EnterQueue(&first);
	DestroyQueue(&first);
	ExitQueue(&first);
	return 0;
}
