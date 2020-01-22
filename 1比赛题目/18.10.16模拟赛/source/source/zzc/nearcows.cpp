#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

namespace Solution_Nearcows
{

template<typename type>
void read(type &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

vector <int> graph[100001];
long long dp1[100001][21];
long long dp2[100001][21];
int vis[100001];
int parent[100001];
long long val[100001];
int k;

void dfs1(int now)
{
	vis[now]=1;
	dp1[now][0]=val[now];
	for(vector<int>::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(!vis[*i])
		{
			parent[*i]=now;
			dfs1(*i);
			for(int j=1;j<=k;j++)
			{
				dp1[now][j]+=dp1[*i][j-1];
			}
		}
	}
}

void dfs2(int now)
{
	vis[now]=2;
	dp2[now][0]=val[now];
	if(now!=1)
	{
		dp2[now][1]=val[parent[now]];
		for(int i=2;i<=k;i++)
		{
			dp2[now][i]=dp2[parent[now]][i-1]+dp1[parent[now]][i-1]-dp1[now][i-2];
		}
	}
	for(vector<int>::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(vis[*i]!=2)
		{
			dfs2(*i);
		}
	}
}

int main()
{
	int n;
	read(n);read(k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u);read(v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		read(val[i]);
	}
	dfs1(1);
	dfs2(1);
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<dp1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<dp2[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		long long ans=-val[i];
		for(int j=0;j<=k;j++)
		{
			ans=ans+dp1[i][j]+dp2[i][j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

}

int main()
{
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	return Solution_Nearcows::main();
}
/*
6 2
5 1
3 6
2 4
2 1
3 2
1 2 3 4 5 6
*/
