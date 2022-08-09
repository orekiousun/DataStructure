#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
struct node
{
	datatype data;
	node *next;
};
void InitStack(node *top)
{
	top->data=0;
	top->next=NULL;
}
void PushStack(node *top)
{
	datatype x;
	printf("��������Ҫ����ջ������");
	scanf("%d",&x); 
	node *s;
	s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=top->next;
	top->next=s;
	top->data++;
}
void PushNumberStack(node *top,datatype x)
{
	node *s;
	s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=top->next;
	top->next=s;
	top->data++;
}
void PopStack(node *top)
{
	node *s;
	if(top->data==0)
	{
		printf("�������ɾ��ʧ��\n");
	}
	else
	{
		s=top->next;
		printf("��ջ����Ϊ��%d\n",s->data);
		top->next=s->next; 
		free(s);
		top->data--;
	}
}
int GetTop(node *top)
{
	if(top->next==NULL)
	{
		printf("��������޷���ȡ\n"); 
	}
	else
	{
		datatype m=top->next->data;
		printf("ջ������Ϊ��%d\n",m);
		return m;
	}
}
void DestroyStack(node *top)
{
	if(top->next==NULL)
	{
		printf("��ջΪ��ջ����������\n");
	}
	else
	{
		while(top->next!=NULL)
		{
			node *s=top->next;
			top->next=s->next;
			free(s);
			top->data--;
		}
	}
}
void GetStack(node *top)
{
	if(top->next==NULL)
	{
		printf("��������޷���ȡ\n"); 
	}
	else
	{
		printf("��ջ����ջβΪ��");
		while(top->next!=NULL)
		{
		datatype m=top->next->data;
		printf("%d ",m);
		top=top->next;
		}
	}
}
void GetLength(node *top)
{
	printf("ջ�е����ݸ���Ϊ��%d",top->data);
} 
void TileStack(node *top1,node *top2,int n,int *a)
{
	int n1=0,n2=n-1;
	for(;;)
	{
		int x;
		printf("��ջ1������1����ջ1������2����ջ2������3����ջ2������4����������������0��");
		scanf("%d",&x);
		if(x==1)
		{
			PushNumberStack(top1,*(a+n1));
			n1++;
		}
		else if(x==2)
		{
			PopStack(top1);
			n1--;
		}
		else if(x==3)
		{
			PushNumberStack(top2,*(a+n2));
			n2--;
		}
		else if(x==4)
		{
			PopStack(top2);
			n2++;
		}
		else
		{
			break;
		}
	}
}
int main()
{
	node top1,top2;
	InitStack(&top1);
	InitStack(&top2);
	int a[100],n=0;
	printf("���������飺"); 
	while(scanf("%d",&a[n])!=0)
	{
		n++;
	}
	getchar(); 
	TileStack(&top1,&top2,n,a);
	GetStack(&top1); 
	printf("\n");
	GetStack(&top2); 
	return 0;
}

//int main()
//{
//	node top;
//	InitStack(&top);
//	for(;;)
//	{
//		int x;
//		printf("��ջ������1����ջ������2����������������0��"); 
//		scanf("%d",&x);
//		if(x==1)
//		{
//		PushStack(&top);
//		}
//		else if(x==2) 
//		{
//			PopStack(&top);
//		}
//		else
//		{
//			break; 
//		}
//	}
//	GetStackh(&top);
//	return 0;
//}
