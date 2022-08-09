#include<stdio.h>
#include<stdlib.h>
#define StackSize 100
int number[1000000];
struct SeqStack
{
	int data[StackSize];
	int top;
};
void InitStack(SeqStack *s)
{
	s->top=0;
}
void Push(SeqStack *s,int x)
{
	if(s->top==StackSize)
	{
		printf("���������ջʧ��"); 
	}
	else
	{
		s->top++;
		s->data[s->top-1]=x;
	}
}
void Pop(SeqStack *s,int *ptr)
{
	if(s->top==0)
	{
		printf("������󣬳�ջʧ��"); 
	}
	else
	{
		*ptr==s->data[s->top-1];
		printf("ջ�����һ����Ϊ��%d" ,*ptr);
		s->top--;
	}
}
void Empty(SeqStack *s)
{
	if(s->top==0)
	{
		printf("��ջΪ��");
	}
	else
	{
		printf("��ջ��Ϊ��");
	} 
}
void GetTop(SeqStack *s)
{
	printf("ջ��Ԫ��Ϊ��%d",s->data[s->top-1]);
}
void DestroyStack(SeqStack *s)
{
	s->top=0;
}
int main()
{
	SeqStack s;
	InitStack(&s);
	Push(&s,5);Push(&s,9);
	GetTop(&s);
}
