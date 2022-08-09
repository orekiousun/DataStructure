#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
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
datatype PushStack(node *top)
{
	datatype x;
	printf("请输入需要放入栈的数：");
	scanf("%c",&x); 
	node *s;
	s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=top->next;
	top->next=s;
	return x;
}
datatype PopStack(node *top)
{
	node *s;
	if(top->next==NULL)
	{
		printf("下溢错误，删除失败\n");
	}
	else
	{
		s=top->next;
		printf("出栈的数为：%c\n",s->data);
		char m=s->data; 
		top->next=s->next; 
		free(s);
		return m;
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
		printf("栈顶数据为：%c\n",m);
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
		printf("%c ",m);
		top=top->next;
		}
	}
}
void func(node *top)
{
	char result[10];
	int i=0;
	for(;;)
	{
		printf("继续请输入1，结束请输入0:");
		int x;
		scanf("%d",&x);
		getchar();
		if(x==1)
		{ 
			char m=PushStack(top);
			if(top->next->data>='a'&&top->next->data<='z')
			{
				result[i]=PopStack(top);i++;
				while(top->next!=NULL)
				{
					if(top->next->data=='*'||top->next->data=='/')
					{
						result[i]=PopStack(top);i++;
						while(top->next!=NULL)
						{
							if(top->next->data=='+'||top->next->data=='-')
							{
								result[i]=PopStack(top);i++;
							}
						}
					}
					else
					{
						break;
					} 
				}
			}
			else
			{
				
			}
		}
		else
		{
			break;
		}
	}
	result[i]=PopStack(top);i++;
	for(int n=0;n<i+1;n++)
	{
		printf("%c ",result[n]);
	}
}
int main()
{
	node top; 
	InitStack(&top);
	func(&top);
	return 0; 
}
