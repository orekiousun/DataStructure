#include<stdio.h> 
int find(int p[],int n)
{
	if(n==0)
	{
		return p[n];
	}
	else if(find(p,n-1)>=p[n])
	{
		return find(p,n-1);
	}
	else
	{
		return p[n];
	} 
}
int main()
{
	int a[9]={1,23,555,66,77,5,3,56,6};
	int max=find(a,9);
	printf("%d",max);
	return 0;
} 
