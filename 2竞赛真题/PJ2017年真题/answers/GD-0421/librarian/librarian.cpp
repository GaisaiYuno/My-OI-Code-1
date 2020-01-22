#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
int n,m,a[10050],x,y;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>a[i];
	sort(1+a,1+a+n);
	//for (int i=1;i<=n;i++)
	 //cout<<a[i]<<endl;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y;bool z1=false;
		for (int j=1;j<=n;j++)
		{
			bool z=true;
			int s=0,p=a[j],q=y;
			while (p>0&&q>0)
			{
				s++;
				if (p%10!=q%10) 
				{z=false;break;}
				p/=10;q/=10;
				if (s==x) break;
			}
			if (z&&s==x) {cout<<a[j]<<endl;z1=true;break;}
		}
		if (!z1) cout<<"-1"<<endl;
	}
	return 0;
}
