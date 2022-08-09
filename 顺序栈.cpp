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
		printf("上溢错误，入栈失败"); 
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
		printf("下溢错误，出栈失败"); 
	}
	else
	{
		*ptr==s->data[s->top-1];
		printf("栈中最后一个数为：%d" ,*ptr);
		s->top--;
	}
}
void Empty(SeqStack *s)
{
	if(s->top==0)
	{
		printf("此栈为空");
	}
	else
	{
		printf("此栈不为空");
	} 
}
void GetTop(SeqStack *s)
{
	printf("栈顶元素为：%d",s->data[s->top-1]);
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
