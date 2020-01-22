#include<cstdio>
#include<cstdlib>
#include<cstring>

int m,n,x,y,c,map[110][110],min[110][110];

void dfs(int p,int q)
{
	if(map[p+1][q]==map[p][q])
	{
		if(min[p][q]<min[p+1][q])
		{
			min[p+1][q]=min[p][q];
			dfs(p+1,q);
		}
	}
	if(map[p-1][q]==map[p][q])
	{
		if(min[p][q]<min[p-1][q])
		{
			min[p-1][q]=min[p][q];
			dfs(p-1,q);
		}
	}
	if(map[p][q+1]==map[p][q])
	{
		if(min[p][q]<min[p][q+1])
		{
			min[p][q+1]=min[p][q];
			dfs(p,q+1);
		}
	}
	if(map[p][q-1]==map[p][q])
	{
		if(min[p][q]<min[p][q-1])
		{
			min[p][q-1]=min[p][q];
			dfs(p,q-1);
		}
	}
	if(map[p+1][q]!=map[p][q] && map[p+1][q]!=-1)
	{
		if(min[p][q]+1<min[p+1][q])
		{
			min[p+1][q]=min[p][q]+1;
			dfs(p+1,q);
		}
	}
	if(map[p-1][q]!=map[p][q] && map[p-1][q]!=-1)
	{
		if(min[p][q]+1<min[p-1][q])
		{
			min[p-1][q]=min[p][q]+1;
			dfs(p-1,q);
		}
	}
	if(map[p][q+1]!=map[p][q] && map[p][q+1]!=-1)
	{
		if(min[p][q]+1<min[p][q+1])
		{
			min[p][q+1]=min[p][q]+1;
			dfs(p,q+1);
		}
	}
	if(map[p][q-1]!=map[p][q] && map[p][q-1]!=-1)
	{
		if(min[p][q]+1<min[p][q-1])
		{
			min[p][q-1]=min[p][q]+1;
			dfs(p,q-1);
		}
	}
	if(map[p+1][q+1]==map[p][q])
	{
		if(min[p][q]+2<min[p+1][q+1])
		{
			min[p+1][q+1]=min[p][q]+2;
			dfs(p+1,q+1);
		}
	}
	if(map[p-1][q-1]==map[p][q])
	{
		if(min[p][q]+2<min[p-1][q-1])
		{
			min[p-1][q-1]=min[p][q]+2;
			dfs(p-1,q-1);
		}
	}
	if(map[p-1][q+1]==map[p][q])
	{
		if(min[p][q]+2<min[p-1][q+1])
		{
			min[p-1][q+1]=min[p][q]+2;
			dfs(p-1,q+1);
		}
	}
	if(map[p+1][q-1]==map[p][q])
	{
		if(min[p][q]+2<min[p+1][q-1])
		{
			min[p+1][q-1]=min[p][q]+2;
			dfs(p+1,q-1);
		}
	}
	if(map[p+1][q+1]!=map[p][q] && map[p+1][q+1]!=-1)
	{
		if(min[p][q]+3<min[p+1][q+1])
		{
			min[p+1][q+1]=min[p][q]+3;
			dfs(p+1,q+1);
		}
	}
	if(map[p-1][q-1]!=map[p][q] && map[p-1][q-1]!=-1)
	{
		if(min[p][q]+3<min[p-1][q-1])
		{
			min[p-1][q-1]=min[p][q]+3;
			dfs(p-1,q-1);
		}
	}
	if(map[p-1][q+1]!=map[p][q] && map[p-1][q+1]!=-1)
	{
		if(min[p][q]+3<min[p-1][q+1])
		{
			min[p-1][q+1]=min[p][q]+3;
			dfs(p-1,q+1);
		}
	}
	if(map[p+1][q-1]!=map[p][q] && map[p+1][q-1]!=-1)
	{
		if(min[p][q]+3<min[p+1][q-1])
		{
			min[p+1][q-1]=min[p][q]+3;
			dfs(p+1,q-1);
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(map,-1,sizeof(map));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
		min[x][y]=10010;
	}
	min[1][1]=0;min[m][m]=10010;
	dfs(1,1);
	if(min[m][m]==10010) printf("-1");
	else printf("%d",min[m][m]);
	return 0;
}
