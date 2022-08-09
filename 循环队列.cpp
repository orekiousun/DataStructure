#include<stdio.h>
#define QueueSize 5
struct CirQueue
{
	int data[QueueSize];
	int front,rear;
};
void InitQueue(CirQueue *q)
{
	q->front=q->rear=0;
}
void Judge(CirQueue *q)
{
	if(q->front==q->rear)
	{
		printf("�ö���Ϊ��\n");
	}
	else if((q->rear+1)%QueueSize==q->front)
	{
		printf("�ö���Ϊ��\n"); 
	}
	else
	{
		printf("�ö��в�Ϊ��\n"); 
	} 
}
void EnterQueue(CirQueue *q,int x)
{
	if((q->rear+1)%QueueSize==q->front)
	{
		printf("������󣬲���ʧ��\n");
	}
	else
	{
		q->data[q->rear]=x;
		q->rear=(q->rear+1)%QueueSize;
	}
}
void ExitQueue(CirQueue *q)
{
	if(q->front==q->rear)
	{
		printf("��������˳�ʧ��\n");
	}
	else
	{
		int m=q->data[q->front];
		printf("�����е���Ϊ��%d\n",m);
		q->front=(q->front+1)%QueueSize;
	}
}
void scan(CirQueue *q)
{
	while(q->front!=q->rear)
	{
		
		int m=q->data[q->front];
		q->front=(q->front+1)%QueueSize;
		printf("%d ",m);
	}
} 
int main()
{
	CirQueue q;
	InitQueue(&q); 
	for(;;)
	{
		int x;
		printf("��ѡ���ܣ�1�����У�2�����У�0����:");
		scanf("%d",&x);
		if(x==1)
		{
			int temp;
			printf("�����������е�����");
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
	scan(&q);
	return 0;		
}






