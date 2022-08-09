#include<stdio.h>
#include<stdlib.h>
void Shift(int r[],int k,int m)
{
	int i=k,j=2*i;
	while(j<=m)
	{
		if(j<m&&r[j]<r[j+1])
		{
			j++;
		}
		if(r[i]>r[j])
		{
			break;
		}
		else
		{
			int temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i=j;
			j=2*i;
		}
	}
} //�����Һ�����ѡ��һ����������ڵ㽻�� 
void HeapSort(int r[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		Shift(r,i,n);
	}

	for(int i=1;i<n;i++)
	{
		int temp=r[1];
		r[1]=r[n-i+1];
		r[n-i+1]=temp;
		Shift(r,1,n-i);
	}
}
int main()
{
	printf("������������Ԫ�ظ���:");
	int n;
	scanf("%d",&n);
	int r[n];
	r[1]=0;
	for(int i=1;i<n;i++)
	{
		r[i]=rand()%101;
	}
	for(int i=1;i<n;i++)
	{
		printf("%d ",r[i]);
	}
	printf("\n");


	HeapSort(r,n-1);
	for(int i=1;i<n;i++)
	{
		printf("%d ",r[i]);
	}
}
