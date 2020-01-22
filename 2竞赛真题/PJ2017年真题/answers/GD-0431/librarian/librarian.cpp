#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,m,check;
string a[1005],w;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		check=0;
		cin>>m;
		char b[1005];
		for(int j=1;j<=m;j++)
		{
		    cin>>b[j];
		}
		string c[1005];
		int s3=0;
		for(int j=1;j<=n;j++)
		{
			w=a[j];
			int s=w.size(),s2=0;
			if(s>=m)
			{
			    for(int z=m;z>=1;z--)
			    {
			        if(b[z]!=w[s-1])
			        {
			        	s2=-1;
			        	break;
			        }
			        s--;
			    }
			    if(s2!=-1)
			    {
			    	s3++;
			    	c[s3]=w;
			    	check=1;
			    }
			}
		}
		if(check==1)
		{
			sort(c+1,c+s3+1);
			if(c[1].size()==c[s3].size())
			{
				cout<<c[1]<<endl;
			}
			else
			{
				int maxs=9999;
				for(int j=1;j<=s3;j++)
				{
					if(c[j].size()<maxs)
					maxs=c[j].size();
				}
				string d[1005];
				int gg=0;
				for(int j=1;j<=s3;j++)
				{
					if(c[j].size()==maxs)
					{
						gg++;
						d[gg]=c[j];
					}
				}
				sort(d+1,d+gg);
				cout<<d[1]<<endl;
			}
		}
		else cout<<"-1"<<endl;
	}
	return 0;
}
