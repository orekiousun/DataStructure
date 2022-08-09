#include<stdio.h> 
#include<stdlib.h>


//Prim算法：先构造满足条件的候选最短边集，再查找最短边:
#define MaxSize 100
void Prim(MGraph *G, int v)/*假设从顶点v出发*/ 
{
	int i,j,k,adjvex[MaxSize],lowcost[MaxSize];
	for(i=0;i<G->vertexNum;i++)
	{
		lowcost[i]=G->edge[v][i];
		adjvex[i]=v;
	} /*初始化辅助数组shortEdge*/
	lowcost[v]=0;/*将顶点v加入集合U*/
	for(k=1;k<G->vertexNum;i++)/*迭代n-1次*/
	{
		j=MinEdge(lowcost,G->vertexNum);/*寻找最短边的邻接点j*/
		printf("(%d,%d)%d ",j,adjvex[j],lowcost[j]); 
		lowcost[j]=0; 
		for (i=0;i<G->vertexNum;i++)/*调整数组shortEdge[n]*/
		{
			if(G->edge[i][j]<lowcost[i]) 
			{
			lowcost[i] = G->edge[i][j]; 
			adjvex[i] = j;
			}
		}
	}
} //Prim算法时间复杂度O（n^2）


//Kruskal算法：先查找最短边，再判断是否满足条件:
#define MaxVertex 10
#define MaxEdge 100
typedef char DataType;
typedef struct
{
	int from,to,weight;
} EdgeType;
typedef struct
{
	DataType vertex[MaxVertex];
	EdgeType edge[MaxEdge];
	int vertexNum, edgeNum;
} EdgeGraph;
int FindRoot(int parent[ ], int v)
{
	int t=v;
	while(parent[t]>-1)
	{
		t=parent[t];
		return t;
	}
}
void Kruskal(EdgeGraph *G)
{
	int i,num=0,vex1,vex2;
	for(i=0;i<G->vertexNum;i++)
	{
		parent[i]=-1; 
	}
	for(num=0,i=0;num<G->vertexNum;i++)
	{
		vex1=FindRoot(parent,G->edge[i].from);
		vex2=FindRoot(parent,G->edge[i].to);
		if (vex1!=vex2)
		{
			printf("(%d,%d)%d",G->edge[i].from,G->edge[i].to,G->edge[i].weight);
			parent[vex2]=vex1;
			num++;
		}
	}
}//Kruskal算法O(elog2e)

//Dijkstra算法:
//对于非带权图，如何求最短路径？ 广度优先遍历
//最短路径：带权图——边上的权值之和最少的路径
//给定带权有向图 G＝(V, E) 和源点 v∈V，求从v到G中其余各顶点的最短路径 
typedef char DataType;
struct MGraph
{
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vertexNum, edgeNum;	
};
//整型数组dist[n]：存储当前最短路径的长度
//字符串数组path[n]：存储当前的最短路径，即顶点序列
void Dijkstra(MGraph *G, int v)/*从源点v出发*/
{
	int i,k,num,dist[MaxSize];
	char *path[MaxSize];
	for(i=0;i<G->vertexNum;i++)/*初始化数组dist[n]和path[n]*/
	{
		dist[i]=G->edge[v][i];
		path[i]=G->vertex[v]+G->vertex[i];/*+为字符串连接操作*/
	}
	for(num=1;num<G->vertexNum;num++)
	{
		for(k=0,i=0;i<G.vertexNum;i++)
		{
			if((dist[i]!=0)&&(dist[i]<dist[k]))
			{
				k=i;
			}
		}
		printf("%s %d "path[k],dist[k]);
		for(i=0;i<G->vertexNum;i++)
		{
			if(dist[i]>dist[k]+G->edge[k][i]) 
			{
				dist[i]=dist[k]+G->edge[k][i]; 
				path[i]=path[k]+G->vertex[i];
			}
		}
		dist[k] = 0;
	}
}//时间复杂度O(n^2) 
 
 //Floyd算法:给定带权有向图G=(V,E),对任意顶点vi和vj(i!=j),求从顶点vi到顶点vj的最短路径
void Floyd(MGraph *G)
{
	int i,j,k,dist[MaxSize][MaxSize];
	for(i=0;i<G->vertexNum;i++)
	{
		for(j=0;j<G->vertexNum；j++)
		{
			dist[i][j]=G->edge[i][j];
		} 
	}
	for(k=0;k<G->vertexNum;k++)
	{
		for(i=0;i<G->vertexNum;i++)
		{
			foor(j=0;j<G->vertexNum;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}//时间复杂度0(n^3) 


