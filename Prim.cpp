#include<stdio.h> 
#include<stdlib.h>


//Prim�㷨���ȹ������������ĺ�ѡ��̱߼����ٲ�����̱�:
#define MaxSize 100
void Prim(MGraph *G, int v)/*����Ӷ���v����*/ 
{
	int i,j,k,adjvex[MaxSize],lowcost[MaxSize];
	for(i=0;i<G->vertexNum;i++)
	{
		lowcost[i]=G->edge[v][i];
		adjvex[i]=v;
	} /*��ʼ����������shortEdge*/
	lowcost[v]=0;/*������v���뼯��U*/
	for(k=1;k<G->vertexNum;i++)/*����n-1��*/
	{
		j=MinEdge(lowcost,G->vertexNum);/*Ѱ����̱ߵ��ڽӵ�j*/
		printf("(%d,%d)%d ",j,adjvex[j],lowcost[j]); 
		lowcost[j]=0; 
		for (i=0;i<G->vertexNum;i++)/*��������shortEdge[n]*/
		{
			if(G->edge[i][j]<lowcost[i]) 
			{
			lowcost[i] = G->edge[i][j]; 
			adjvex[i] = j;
			}
		}
	}
} //Prim�㷨ʱ�临�Ӷ�O��n^2��


//Kruskal�㷨���Ȳ�����̱ߣ����ж��Ƿ���������:
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
}//Kruskal�㷨O(elog2e)

//Dijkstra�㷨:
//���ڷǴ�Ȩͼ����������·���� ������ȱ���
//���·������Ȩͼ�������ϵ�Ȩֵ֮�����ٵ�·��
//������Ȩ����ͼ G��(V, E) ��Դ�� v��V�����v��G���������������·�� 
typedef char DataType;
struct MGraph
{
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vertexNum, edgeNum;	
};
//��������dist[n]���洢��ǰ���·���ĳ���
//�ַ�������path[n]���洢��ǰ�����·��������������
void Dijkstra(MGraph *G, int v)/*��Դ��v����*/
{
	int i,k,num,dist[MaxSize];
	char *path[MaxSize];
	for(i=0;i<G->vertexNum;i++)/*��ʼ������dist[n]��path[n]*/
	{
		dist[i]=G->edge[v][i];
		path[i]=G->vertex[v]+G->vertex[i];/*+Ϊ�ַ������Ӳ���*/
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
}//ʱ�临�Ӷ�O(n^2) 
 
 //Floyd�㷨:������Ȩ����ͼG=(V,E),�����ⶥ��vi��vj(i!=j),��Ӷ���vi������vj�����·��
void Floyd(MGraph *G)
{
	int i,j,k,dist[MaxSize][MaxSize];
	for(i=0;i<G->vertexNum;i++)
	{
		for(j=0;j<G->vertexNum��j++)
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
}//ʱ�临�Ӷ�0(n^3) 


