#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
long long n,z,k,p;
string st[1000+5],st1,st2,stt;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>z;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];
	}
	for (int i=1;i<=n-1;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (st[i].size()>st[j].size())
			{
				st1=st[i];
				st[i]=st[j];
				st[j]=st1;
			}
			if (st[i].size()==st[j].size())
			{
				for (int q=0;q<st[i].size();q++)
				{
					if (st[i][q]>st[j][q])
					{
							st1=st[i];
				            st[i]=st[j];
				            st[j]=st1;
				            break;
					}
				}
			}
		}
	}
	for (int i=1;i<=z;i++)
	{
		cin>>k>>stt;
		p=0;
		st2="";
		for (int j=1;j<=n;j++)
		{
		    for (int q=st[j].size()-k;q<st[j].size();q++)
		    {
		    	st2=st2+st[j][q];
		    }
			if (st2==stt)
			{
				cout<<st[j]<<endl;
				p=1;
				break;
			}
			st2="";
		}
		if (p==0)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
