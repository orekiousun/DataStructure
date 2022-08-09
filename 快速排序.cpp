#include<stdio.h>
#include<stdlib.h>
void QuickSort(int a[],int first,int end) 
{
	int num=end+1;
	int n=a[first];
	if(first==end)
	{
		return;
	}
	if(first<end)
	{
		while(first<end)
		{
			while(first<end&&a[first]<=a[end])
			{
				end--;//endÖ¸ï¿½ï¿½Ç°ï¿½Æ£ï¿½Ö±ï¿½ï¿½a[first]>=a[end]
			}
			if(first<end)
			{
				a[first]=a[end];
			}
			while(first<end&&a[first]<=a[end])
			{
				first++;//firstÖ¸ï¿½ï¿½ï¿½ï¿½Æ£ï¿½Ö±ï¿½ï¿½a[first]>=a[end]
			}
			if(first<end)
			{
				a[end]=a[first];
			}
		}
		a[first]=n;
		QuickSort(a,0,first-1);
		QuickSort(a,first+1,num-1);
	}
}
int main()
{
	printf("ÇëÊäÈëÊı×éÔªËØ¸öÊı£º6");
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
	QuickSort(r,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",r[i]);
	}
	return 0;
}
