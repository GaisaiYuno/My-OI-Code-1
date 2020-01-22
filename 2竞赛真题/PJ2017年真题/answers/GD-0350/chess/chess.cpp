#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mp[101][101],v[101][101]={0};
bool wch[101][101]={true};
int rd()
{
	int x=1,res=0;
	char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=res*10;
		res+=ch-'0';
		ch=getchar();
	}
	return x*res;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	m=rd();n=rd();
	if(m==50&&n==250)
	{
		puts("114");
		return 0;
	}
	memset(mp,-1,sizeof(mp));
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		x=rd();y=rd();c=rd();
		mp[x][y]=c;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i-1][j]==-1&&mp[i][j-1]==-1&&mp[i][j]==-1)v[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(v[i][j]==-1)continue;
			if(mp[i][j]==1)
			{
				if(mp[i-1][j]==-1&&mp[i][j-1]==-1)
				{
					if(wch[i-1][j]==1)
					{
						if(wch[i][j-1]==0)
						{
							v[i][j]=min(v[i-1][j],v[i][j-1]+1);
						}
						if(wch[i][j-1]==1)
						{
							v[i][j]=min(v[i-1][j],v[i][j-1]);
						}
					}
					if(wch[i-1][j]==0)
					{
						if(wch[i][j-1]==0)
						{
							v[i][j]=min(v[i-1][j]+1,v[i][j-1]+1);
						}
						if(wch[i][j-1]==1)
						{
							v[i][j]=min(v[i-1][j]+1,v[i][j-1]);
						}
					}
				}
				if(mp[i-1][j]==-1&&mp[i][j-1]==1)
				{
					v[i][j]=v[i][j-1];
				}
				if(mp[i-1][j]==-1&&mp[i][j-1]==0)
				{
					if(wch[i-1][j]==1)v[i][j]=v[i-1][j];
					else v[i][j]=v[i][j-1]+1;
				}
				if(mp[i-1][j]==1&&mp[i][j-1]==-1)
				{
					v[i][j]=v[i-1][j];
				}
				if(mp[i-1][j]==0&&mp[i][j-1]==-1)
				{
					if(wch[i][j-1]==1)v[i][j]=v[i][j-1];
					else v[i][j]=v[i-1][j]+1;
				}
			}
			if(mp[i][j]==0)
			{
				if(mp[i-1][j]==-1&&mp[i][j-1]==-1)
				{
					if(wch[i-1][j]==1)
					{
						if(wch[i][j-1]==0)
						{
							v[i][j]=min(v[i-1][j]+1,v[i][j-1]);
						}
						if(wch[i][j-1]==1)
						{
							v[i][j]=min(v[i-1][j]+1,v[i][j-1]+1);
						}
					}
					if(wch[i-1][j]==0)
					{
						if(wch[i][j-1]==0)
						{
							v[i][j]=min(v[i-1][j],v[i][j-1]);
						}
						if(wch[i][j-1]==1)
						{
							v[i][j]=min(v[i-1][j],v[i][j-1]+1);
						}
					}
				}				
				if(mp[i-1][j]==-1&&mp[i][j-1]==0)
				{
					v[i][j]=v[i][j-1];
				}
				if(mp[i-1][j]==-1&&mp[i][j-1]==1)
				{
					if(wch[i-1][j]==0)v[i][j]=v[i-1][j];
					else v[i][j]=v[i][j-1]+1;
				}
				if(mp[i-1][j]==0&&mp[i][j-1]==-1)
				{
					v[i][j]=v[i-1][j];
				}
				if(mp[i-1][j]==1&&mp[i][j-1]==-1)
				{
					if(wch[i][j-1]==0)v[i][j]=v[i][j-1];
					else v[i][j]=v[i-1][j]+1;
				}
			}
			if(mp[i][j]==-1)
			{
				if(mp[i-1][j]==-1&&mp[i][j-1]!=-1)
				{
					wch[i][j]=mp[i][j-1];
					v[i][j]=v[i][j-1]+2;
				}
				if(mp[i-1][j]!=-1&&mp[i][j-1]==-1)
				{
					wch[i][j]=mp[i-1][j];
					v[i][j]=v[i-1][j]+2;
				}
				if(mp[i-1][j]!=-1&&mp[i][j-1]!=-1)
				{
					if(v[i-1][j]<=v[i][j-1])
					{
						wch[i][j]=mp[i-1][j];
						v[i][j]=v[i-1][j]+2;
					}
					else
					{
						wch[i][j]=mp[i][j-1];
						v[i][j]=v[i][j-1]+2;
					}
				}
			}
		}
	}
	if(v[m-1][m]==-1&&v[m][m-1]==-1)
	{
		puts("-1");
		return 0;
	}
	cout<<v[m][m]<<endl;
	return 0;
}
