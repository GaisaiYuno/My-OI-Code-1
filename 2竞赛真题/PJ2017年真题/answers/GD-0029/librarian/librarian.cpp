#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
int n,q,ji;
struct node
{
	int lth;
	int ed;
}num[1010],rder[1010];
bool _cmp(node a,node b)
{
	return a.ed<b.ed;
}
int Isjs(int ws)
{
	int sum=1;
	for (int i=1; i<=ws; i++) sum*=10;
	return sum;
}
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++) 
	{
		string st;
		ji=1;
		cin>>st;
		num[i].lth=st.size();
		for (int j=num[i].lth-1; j>=0; j--)
		{
		   num[i].ed+=(st[j]-48)*ji;
		   ji*=10;	
		}
	}
	
	
	for (int i=1; i<=q; i++) scanf("%d%d",&rder[i].lth,&rder[i].ed);
	sort(num+1,num+n+1,_cmp);
	for (int i=1; i<=q; i++)
	{
		int _judge=-1;
		for (int j=1; j<=n; j++)
		{
			if (_judge==1) break;
			if (rder[i].lth==num[j].lth&&rder[i].ed==num[j].ed) 
			{ 
			  cout<<num[j].ed<<endl;
			  _judge=1;
		    }
		    else if (num[j].lth<rder[i].lth) continue;
			else if (rder[i].lth<num[j].lth)
			{
				int MMOD=Isjs(rder[i].lth);
				if (num[j].ed%MMOD==rder[i].ed) 
				{
					cout<<num[j].ed<<endl;
					_judge=1;
				}
			}
		}
		if (_judge==-1) cout<<-1<<endl;
	}			
	return 0;
}
