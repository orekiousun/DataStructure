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
}//�ҵİ취������

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
//��ʦ�İ취������r[0]�ݴ��̽���a[i]�����ȫ�����ں��� 
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
	printf("\n");
	InsertSort(r,n);
	return 0; 
}

