#include<stdio.h>
#include<stdlib.h>
struct Hash
{
	int data;
	Hash *next;
};
void HashInit(Hash first[],int m)
{
	for(int i=0;i<m;i++)
	{
		first[i].next=NULL;
	}
}
void HashCreat(Hash first[],int m)
{
	for(int i=0;i<m;i++)
 	{
 		int temp;
 		temp=rand()%101; 
 		int j=temp%m;
 		Hash *s;
 		s=(Hash *)malloc(sizeof(Hash));
 		s->data=temp;
 		s->next=first[j].next;
		first[j].next=s;
 		printf("first[j].next->data=%d\n",first[j].next->data);
	} 
}
int HashSearch(Hash first[],int m,int number)
{
	int j=number%m;
	Hash *s=first[j].next;
	for(;;)
	{
		if(s->data==number)
		{
			return 1;
			break;
		}
		else if(s->next==NULL)
		{
			return 0;
			break;
		}
		else
		{
			s=s->next;
		}
	}
}
void HashDelete(Hash first[],int number,int m)
{
	int j=number%m;
	Hash *s=first[j].next;
	if(s->data==number)
	{
		first[j].next=s->next;
		free(s);	
	}
	else
	{
		Hash *s0=s;
		s=s->next;
	}
	while(s!=NULL)
	{
		if(s->data==number)
		{
			s0->next=s->next;
			free(s);	
		}
		else
		{
			s0=s;
			s=s->next;
		}
	}
 } 
int main()
{
	printf("������������Ԫ�ظ���:");
	int n;
	scanf("%d",&n);
	Hash first[n];
	HashInit(first,n);
	HashCreat(first,n);
	printf("����������ҵ�ֵ��");
	int k;
	scanf("%d",&k);
	int m=HashSearch(first,n,k);
	printf("%d",m);
	return 0;
}
