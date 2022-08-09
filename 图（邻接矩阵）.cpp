#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 10
typedef char DataType;
int visitedDF[100]={0};
int visitedBF[100]={0};
struct MGraph
{
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vertexNum, edgeNum;	
};
void CreatGraph(MGraph *G,DataType a[],int n,int e)
{
	
	int i,j,k;
	G->vertexNum=n;
	G->edgeNum=e;
	for(i=0;i<G->vertexNum;i++)
	{
		G->vertex[i]=a[i];
	}
	for(i=0;i<G->vertexNum;i++)
	{
		for(j=0;j<G->vertexNum;j++)
		{
			G->edge[i][j]=0;
		}
	}
	for(k=0;k<G->edgeNum;k++)
	{
		scanf("%d%d",&i,&j);
		G->edge[i][j]=1;
		G->edge[j][i]=1;
	}
}
void DFTraverse(MGraph *G, int v)
{
	printf("%c ",G->vertex[v]);
	visitedDF[v]=1;
	for(int j=0;j<G->vertexNum;j++)
	{
		if(G->edge[v][j]==1&&visitedDF[j]==0)
		{
			DFTraverse(G,j);
		}
	}
}
void BFTraverse(MGraph *G, int v)//队列 
{
	int i,j,Q[MaxSize];
	int front=-1,rear=-1;
	printf("%c ",G->vertex[v]);
	visitedBF[v]=1;
	rear++;
	Q[rear]=v;//入队 
	while(front!=rear)
	{
		front++;
		i=Q[front];//出队 
		for(j=0;j<G->vertexNum;j++)
		{
			if(G->edge[i][j]==1&&visitedBF[j]==0)
			{
				printf("%c ",G->vertex[j]);
				visitedBF[j]=1;
				rear++;
				Q[rear]=j;
			}
		}
	}
}

int visited[MaxSize];
void CreatTree(MGraph *G)
{
	MGraph *New;
	New->vertexNum=G->vertexNum;
	New->edgeNum=0;
	for(i=0;i<G->vertexNum;i++)
	{
		G->vertex[i]=New->vertex[i];
	}
	for(int i=0;i<G->vertexNum;i++)
	{
		for(int j=0;j<G->vertexNum;j++)
		{
			if(G->edge[i][j]==1&&visited[i]!=1)
			{
				visited[i]=1;
				New->edge[i][j]=1;
				New->edge[j][i]=1;
				New->edgeNum++;
			}
		}
	}
}
int main()
{
	MGraph G;
	char a[6]={'0','1','2','3','4','5'}; 
	CreatGraph(&G,a,6,7); 
	BFTraverse(&G,0);
	printf("\n");
	DFTraverse(&G,0);
	return 0;	
}; 
