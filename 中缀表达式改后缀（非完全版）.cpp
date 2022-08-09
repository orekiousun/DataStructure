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
	printf("��������Ҫ����ջ������");
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
		printf("�������ɾ��ʧ��\n");
	}
	else
	{
		s=top->next;
		printf("��ջ����Ϊ��%c\n",s->data);
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
		printf("��������޷���ȡ\n"); 
	}
	else
	{
		datatype m=top->next->data;
		printf("ջ������Ϊ��%c\n",m);
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
		printf("����������1������������0:");
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
