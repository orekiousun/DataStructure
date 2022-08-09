#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[10];
	srand((int)time(0));
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%101;//%11表示10以内，%101表示100以内； 
		printf("n=%d\n",a[i]);
	}

 	system("pause");
 	return 0;
 }
