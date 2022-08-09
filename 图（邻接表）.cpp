#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
int visitedBF[100]={0};
int visitedDF[100]={0};
typedef char DataType;
struct EdgeNode
{
	int adjvex;
	EdgeNode *next;	
};
struct VertexNode
{
	DataType vertex;
	EdgeNode *first;
};
struct ALGraph
{
	VertexNode adjlist[MaxSize];
	int vertexNum,edgeNum;
};
void CreatGraph(ALGraph *G,DataType a[],int n,int e)
{
	int i,j,k;
	G->edgeNum=e;
	G->vertexNum=n;
	EdgeNode *s=NULL;
	for(i=0;i<G->vertexNum;i++)
	{
		G->adjlist[i].vertex=a[i];
		G->adjlist[i].first=NULL;
	}
	for(k=0;k<G->edgeNum;k++)
	{

		scanf("%d%d",&i,&j);
		s=(EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex=j;
		s->next=G->adjlist[i].first;
		G->adjlist[i].first=s;//头插法 
	}
}
void DFTraverse(ALGraph *G,int v) 
{
	EdgeNode *p=NULL;
	int j;
	printf("%c ",G->adjlist[v].vertex);
	visitedDF[v]=1;
	p=G->adjlist[v].first;
	while(p!=NULL)
	{
		j=p->adjvex;
		if(visitedDF[j]==0)
		{
			DFTraverse(G,j);
		}
		p=p->next;
	}
}
void BFTraverse(ALGraph *G,int v)
{
	int a[MaxSize];
	int front=-1,rear=-1;
	EdgeNode *p=NULL;
	int i,j;
	printf("%c ",G->adjlist[v].vertex);
	visitedBF[v]=1;
	rear++;
	a[rear]=v;
	while(front!=rear)
	{
		front++;
		i=a[front];
		p=G->adjlist[i].first;
		while(p!=NULL)
		{
			j=p->adjvex;
			if(visitedBF[j]==0)
			{
				printf("%c ",G->adjlist[j].vertex);
				visitedBF[j]=1;
				rear++;
				a[rear]=p->adjvex;
			}
			p=p->next;
		}
	}		
} 
void DestroyGraph(ALGraph *G)
{
	EdgeNode *p=NULL,*q=NULL;
	for(int i=0;i<G->vertexNum;i++)
	{
		p=q=G->adjlist[i].first;
		while(p!=NULL)
		{
			p=p->next;
			free(q);
			q=p;
		}
	}
}
int JudgeGraph(ALGraph *G,int j,int i)
{
	DataType m=G->adjlist[j]->vertex;
	EdgeNode *s=G->adjlist[i]->first; 
	int counter=0;
	while(s->next!=NULL)
	{
		if(s->adjvex==m)
		{
			counter=1;
			return 1;
		}
		else
		{
			s=s->next;
		}	
	}	
	if(counter==0)
	{
		return 0;
	}
}
void TransferGraph(ALGraph *G)
{
	ALGraph *T;
	for(int i=0;i<MaxSize;i++)
	{
		EdgeNode *p=G->adjlist[i]->first;
		DataType n=G->adjlist[i]->vertex;//头上的数据 
		while(p!=NULL)
		{
			EdgeNode *s=(EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex=n;
			DataType m=p->adjvex;//边尾部数据 
			EdgeNode *s1=T->adjlist[m]->first;
			while(s1!=NULL)
			{
				s1=s1->next;
			}
			s1=s;
			p=p->next; 
		}
	}
}
int main()
{
	ALGraph G;
	char a[6]={'0','1','2','3','4','5'}; 
	CreatGraph(&G,a,6,7);
	BFTraverse(&G,0);
	printf("\n");
	DFTraverse(&G,0);
	return 0;
} 
