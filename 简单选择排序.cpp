#include<stdio.h>
#include<stdlib.h>
void SelectSort(int r[],int n)
{
	for(int j=1;j<n;j++)
	{
		int min=j;
		for(int i=j;i<n-1;i++)
		{
			if(r[min]<=r[i+1])
			{
				min=min;
			}
			else
			{
				min=i+1;
			}
		}
		if(r[min]<r[j-1])
		{
			int temp=r[min];
			r[min]=r[j-1];
			r[j-1]=temp;
		}
	}
}
int main()
{
	printf("������������Ԫ�ظ���:");
	int n;
	scanf("%d",&n);
	int r[n];
	for(int i=0;i<n;i++)
	{
		r[i]=rand()%101;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",r[i]);
	}
	SelectSort(r,n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",r[i]);
	}
	return 0;
}
