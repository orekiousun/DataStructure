#include<stdio.h>
#include<stdlib.h>
void Merge(int r[],int left,int mid,int right)
{
	int temp[right-left+1];
	int i=left,j=mid+1,k=0;
	while(i<=mid&&j<=right)
	{
		if(r[i]<=r[j])
		{
			temp[k++]=r[i++];
		}
		else
		{
			temp[k++]=r[j++];
		}
	}
	if(i>mid)
	{
		while(j<=right)
		{
			temp[k++]=r[j++];
		}
	}
	if(j>right)
	{
		while(i<=mid)
		{
			temp[k++]=r[i++];
		}
	}
	

	for(int m=0;m<k;m++)
	{
		r[left]=temp[m];
		left++;
	}
}
void MergeSort(int r[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		MergeSort(r,left,mid);   
        MergeSort(r,mid+1,right);
        Merge(r,left,mid,right);         
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
	MergeSort(r,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",r[i]); 
	}
	return 0;
}
