#include<stdio.h>
#include<stdlib.h>
int number[1000000];
struct node
{
	int data;
    node *next;
};
void Initlist(node *first)
{
	first->data=0;
	first->next=NULL;
};
void Printlist(node *first)
{
	node *p=first->next;
	for(int i=0;i<first->data;i++)
	{
		printf("%d ",p->data);
		p=p->next;
	}
};
void Insert(node *first,int n,int x) 
{
	node *p=first->next;
	node *l;
	l=(node *)malloc(sizeof(node));
	l->data=x;
	if(n<=1)
	{
		first->next=l;
		l->next=p;	
	}
	else if(n>first->data)
	{
		printf("error");
	}
	else
	{
	for(int i=1;i<n-1;i++)
	{
		p=p->next;
		
	}
		l->next=p->next;
		p->next=l;
	}
	
	
	first->data++;
}
void Delete(node *first,int n)
{
	node *p=first->next;
	if(n==1)
	{
		first->next=p->next;
	}
	else if(n>first->data)
	{
		printf("error");
	}
	else
	{
	for(int i=0;i<n-2;i++)
	{
		p=p->next;
	}
	node *temp;
	temp=p->next;
	p->next=temp->next;
	free(temp);	
	}
	first->data--;
}
void Searchdelete(node *first,int x)
{
	node *p=first->next;
	if(p->data==x)
	{
		first->next=p->next;
	}
	else
	{
	int i=0;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			break;
		}
		else
		{
			p=p->next;
			i++;
		}
	} 
	i++;
	node *l=first->next;
	for(int k=0;k<i-2;k++)
	{
		l=l->next;
	}
	l->next=l->next->next;
	}
	first->data--;
}
void Destroy(node *first)
{
	node *p=first->next;
	for(int i=0;i<first->data;i++)
	{
		node *temp;
		temp=p;
		p=p->next;
		free(temp);
	}
	first->data=0;
	first->next=NULL;
}
void Creatlist(node *first)
{
	int i=first->data;
	while(scanf("%d",&number[i]),number[i]!=-1)
	{
		i++;
	}
	first->data=i;
	node *s=NULL;
	first->next=NULL;
	for(int k=i-1;k>=0;k--)
	{
		s=(node *)malloc(sizeof(node));
		s->data=number[k];
		s->next=first->next;
		first->next=s;
	}//创建表只能倒序插入 
	printf("创建成功\n");
};
void Tile(node *first1,node *first2,node *first)
{
	node *p1=first1->next,*p2=first2->next;
	int m=first1->data;
	int n=first2->data;
	int list1[m],list2[n],list[m+n];
	int i=0;
	for(;i<m;i++)
	{
		list[i]=p1->data;
		p1=p1->next;
	}
	for(;i<m+n;i++)
	{
		list[i]=p2->data;
		p2=p2->next;
	}
	for(int k=m+n;k>0;k--)
	{
		for(int l=1;l<k;l++)
		{
			if(list[l]>list[l-1])
			{
				int temp=list[l];
				list[l]=list[l-1];
				list[l-1]=temp;
			}
			else
			{
			
			}
		}
	}
	first->data=m+n;
	node *p=NULL;
	first->next=NULL;
	for(int k=m+n-1;k>=0;k--)
	{
		p=(node *)malloc(sizeof(node));
		p->data=list[k];
		p->next=first->next;
		first->next=p;
	}
};
void Josephus(node *first)
{
	int number;
	printf("请输入循环周期：");
	scanf("%d",&number);
	node *p=first->next;
	for(int i=0;i<first->data-1;i++)
	{
		p=p->next;
	}
	p->next=first->next;
	p=p->next;
	int i=1;
	while(first->data!=1)
	{
		if(i%number==number-1)
		{
			node *temp;
			temp=p->next;
			p->next=temp->next;
			free(temp);	//此时指针必须在i个节点处才能删除 i+1和节点，同时跳到i+2节点处 
			p=p->next;
			first->data--;
			i++;
		} 
		else
		{
			p=p->next;
		}
		i++;
	}
	printf("%d",p->data);
}
void Judge(node *first)
{
	node *p=first->next;
	int j=1; 
	for(int i=1;i<first->data;i++)
	{
		if(p->data<p->next->data)
		{
			j++;
		}
		else
		{
			printf("此链表不递增有序\n"); 
			break;
		}
		p=p->next;
	}
	if(j==first->data)
	{
		printf("此链表递增有序\n"); 
	}
}
void Double(node *first)
{
	node *p=first->next;
	int m=2*first->data;
	first->data=m;
	int data[m];
	for(int k=0;k<m;k++,k++)
	{
		data[k]=p->data;
		data[k+1]=p->data;
		p=p->next;
	}
	node *s=NULL;
	first->next=NULL;
	for(int k=m-1;k>=0;k--)
	{
		s=(node *)malloc(sizeof(node));
		s->data=data[k];
		s->next=first->next;
		first->next=s;
	}
	printf("创建成功\n");
}
void TargetDelete(node *first,int mink,int maxk)
{
	
	node *p=first->next;
	int count=0;
	for(int i=0;i<first->data-1;i++)
	{
		if((p->next->data>mink)&&(p->next->data<maxk))
		{
			node *temp;
			temp=p->next;
			printf("p->data=%d\n",p->data);
			p->next=temp->next;                       //如果写成p=temp->next的话，p的后继指针就没有改变； 
			printf("p->data=%d\n",p->data);
			free(temp);
			count++;
		}
		else
		{
			p=p->next;
		}

	}
	first->data=first->data-count;
} 


int main()
{
	node first1,first2,first;
	Initlist(&first1);
	Creatlist(&first1);
	Initlist(&first2);
	Creatlist(&first2);
	Tile(&first1,&first2,&first);
	Printlist(&first);
	return 0;
}
