#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
class list
{
	private:
		string listpart;
		string listhole;
		int count;
	public:
		void getpart(string b)
		{
			listpart=b;
		} 
		void gethole(string a)
		{
			listhole=a;
		}
		void getcount(int w)
		{
			count=w;
		}
		int judge(int a,int b)
		{
			string::iterator p1;
			string::iterator p2;
			for(p1=listhole.begin(),p2=listpart.begin();p1!=listhole.end()&&p2!=listpart.end();)
			{
				if(*p1==*p2)
				{
					p2++;
					p1++;
					count++;
				}
				else
				{
					p1++;	
				}
			}
			if(count==b)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};
int main()
{
	list m,n;
	string a,b,c;
	cout<<"����ĸ����1��"; 
	cin>>a;
	cout<<"����ĸ����2��";
	cin>>c;
	cout<<"���������У�";
	cin>>b;
	m.gethole(a);
	m.getpart(b);
	m.getcount(0);
	n.gethole(c);
	n.getpart(b);
	n.getcount(0);
	int x=a.length(),y=b.length(),z=c.length();
	int result1=m.judge(x,y);
	int result2=n.judge(z,y);
	if(result1==1&&result2==1)
	{
		cout<<"Ϊ����������"<<endl; 
	}
	else
	{
		cout<<"��Ϊ����������"<<endl;
	}
	return 0;
}
