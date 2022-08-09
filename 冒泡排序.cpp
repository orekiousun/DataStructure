#include<stdio.h> 
#include<stdlib.h>
void BubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<=a[j-1])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	 } 
}
int main()
{
	printf("请输入数组中元素个数:");
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
	printf("\n");
	BubbleSort(r,n);
	return 0;
}
