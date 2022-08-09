#include<stdio.h>
#include<stdlib.h>
void HashCreat(int ht[],int m)
{
	int visited[m]={0};
	for(int i=0;i<m;i++)
	{
		int temp,number;
		temp=rand()%101;
		number=temp%m;
		if(visited[number]==0)
		{
			ht[number]=temp;
			visited[number]=1;
		}
		else
		{
			while(visited[number]==1)
			{
				number=(number+1)%m;
			}
			ht[number]=temp;
			visited[number]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		printf("%d ",ht[i]);
	}
	printf("\n");
} 
int HashSearch(int ht[],int m,int number)
{
	int j=number%m;
	if(ht[j]==number)
	{
		return 1;
	}
	else
	{
		for(int i=0;;i++)
		{
			j=(j+1)%m;
			if(ht[j]==number)
			{
				return 1;
				break;
			}
			else if(i==m-2)
			{
				return 0;
				break;
			}
			else
			{
				
			}
		}	
	}	
}
int main()
{
	printf("请输入数组中元素个数:");
	int n;
	scanf("%d",&n);
	int ht[n];
	HashCreat(ht,n);
	printf("请输入待查找的值：");
	int k;
	scanf("%d",&k);
	int i=HashSearch(ht,n,k);
	printf("%d",i);
	return 0;
} 
