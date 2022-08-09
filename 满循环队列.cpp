#include<stdio.h>
#define QueueSize 5
struct CirQueue
{
	int data[QueueSize];
	int front,rear,tag;
};
void InitQueue(CirQueue *q)
{
	q->front=q->rear=0;
	q->tag=0;
}
void Judge(CirQueue *q)
{
	if(q->tag==0)
	{
		printf("该队列为空\n");
	}
	else if((q->rear)%QueueSize==q->front&&q->tag!=0)
	{
		printf("该队列为满\n"); 
	}
	else
	{
		printf("该队列不为空\n"); 
	} 
}
void EnterQueue(CirQueue *q,int x)
{
	if(((q->rear)%QueueSize==q->front)&&q->tag!=0) 
	{
		printf("上溢错误，插入失败\n");
	}
	else
	{
		q->data[q->rear]=x;
		q->rear=(q->rear+1)%QueueSize;
		q->tag++;
	}
}
void ExitQueue(CirQueue *q)
{
	if(q->tag==0)
	{
		printf("下溢错误，退出失败\n");
	}
	else
	{
		int m=q->data[q->front];
		printf("出队列的数为：%d\n",m);
		q->front=(q->front+1)%QueueSize;
		q->tag--;
	}
}
void scan(CirQueue *q)
{
	int number=q->tag;
	while(q->front!=q->rear||q->tag!=0)
	{
		int m=q->data[q->front];
		q->front=(q->front+1)%QueueSize;
		printf("%d ",m);
		q->tag--;
	}
	q->tag=number;
} 
int main()
{
	CirQueue q;
	InitQueue(&q); 
	for(;;)
	{
		int x;
		printf("请选择功能：1进队列，2出队列，0结束:");
		scanf("%d",&x);
		if(x==1)
		{
			int temp;
			printf("请输入进入队列的数：");
			scanf("%d",&temp); 
			EnterQueue(&q,temp);
		}
		else if(x==2)
		{
			ExitQueue(&q);
		}
		else
		{
			break;	
		} 
	}
	Judge(&q);
	scan(&q);
	return 0;		
}
