#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
    node *next;
};
void InsertSort(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			else
			{
				
			}
		}
		for(int v=0;v<n;v++)
		{
			printf("%d ",a[v]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}//我的办法：交换

void InsertSort1(int r[], int n) 
{
	int i,j;
    for (i=2;i<=n;i++)
    { 
		r[0]=r[i];
		j=i-1; 
        while(r[0]<r[j])
        {
            r[j+1]=r[j];   
            j--;  
        }           
		r[j+1]=r[0];
	}
}       
//老师的办法：利用r[0]暂存盘将比a[i]大的数全部放在后面 
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
	InsertSort(r,n);
	return 0; 
}

