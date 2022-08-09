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
	printf("请输入需要放入栈的数：");
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
		printf("下溢错误，删除失败\n");
	}
	else
	{
		s=top->next;
		printf("出栈的数为：%d\n",s->data);
		top->next=s->next; 
		free(s);
		top->data--;
	}
}
int GetTop(node *top)
{
	if(top->next==NULL)
	{
		printf("下溢错误，无法读取\n"); 
	}
	else
	{
		datatype m=top->next->data;
		printf("栈顶数据为：%d\n",m);
		return m;
	}
}
void DestroyStack(node *top)
{
	if(top->next==NULL)
	{
		printf("此栈为空栈，无需销毁\n");
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
		printf("下溢错误，无法读取\n"); 
	}
	else
	{
		printf("从栈顶到栈尾为：");
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
	printf("栈中的数据个数为：%d",top->data);
} 
void TileStack(node *top1,node *top2,int n,int *a)
{
	int n1=0,n2=n-1;
	for(;;)
	{
		int x;
		printf("入栈1请输入1，出栈1请输入2，入栈2请输入3，出栈2请输入4，结束操作请输入0：");
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
	printf("请输入数组："); 
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
//		printf("入栈请输入1，出栈请输入2，结束操作请输入0："); 
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
