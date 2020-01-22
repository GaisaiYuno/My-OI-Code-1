#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

namespace Solution
{
const int LIMIT=7;
//const int MAXTIME=1000000000;
const int INF=0x3f3f3f3f;
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

vector <pair<int,int> > graph[200001];
vector <pair<pair<int,int>,int> > edge;
struct cmp
{
	bool operator()(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b)const
	{
		return a.second<b.second;
	}
};
void addedge(int u,int v,int w)
{
//	cout<<"addedge("<<u<<" "<<v<<" "<<w<<")"<<endl;
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}
char map[2005][2005];
int city[2005][2005];
pair<int,int> pcity[200005];
int maxn[200005][19];
int parent[200005][19];
int height[200005];
int color[200005];
bool vis2[200005];
int H,W;
struct point_t
{
	int x,y;
	int dis;
};
queue <point_t> q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[2005][2005];
int times;

void bfs(int startx,int starty,int startcity,int xl,int xr,int yl,int yr)
{
//	printf("bfs(%d,%d,%d,%d,%d,%d,%d)\n",startx,starty,startcity,xl,xr,yl,yr);
	while(!q.empty())q.pop();
	q.push((point_t){startx,starty,0});
	times++;
	int edgeadded=0;
//	int searchtimes=0;
	while(!q.empty())
	{
//		searchtimes++;
//		if(searchtimes>MAXTIME)return;
		point_t now=q.front();
		q.pop();
//		cout<<"now="<<now.x<<" "<<now.y<<" "<<now.dis<<endl;
		if(city[now.x][now.y]!=startcity&&city[now.x][now.y]!=0)
		{
//			cout<<"addedge"<<startcity<<" "<<city[now.x][now.y]<<" "<<now.dis-1<<endl;
			edge.push_back(make_pair(make_pair(startcity,city[now.x][now.y]),now.dis-1));
			edgeadded++;
			if(edgeadded>LIMIT)return;
			continue;
		}
		for(int i=0;i<4;i++)
		{
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>xr||nx<xl||ny>yr||ny<yl)continue;
			if(map[nx][ny]=='#'||vis[nx][ny]==times)continue;
			q.push((point_t){nx,ny,now.dis+1});
			vis[nx][ny]=times;
		}
	}
}

void init_edge(int n)
{
	for(int i=1;i<=n;i++)
	{
		int &x=pcity[i].first,&y=pcity[i].second;
	//	bfs(x,y,i,1,x,1,y);
	//	bfs(x,y,i,1,x,y,W);
	//	bfs(x,y,i,x,H,1,y);
		bfs(x,y,i,1,H,1,W);
	}
}

int fa[200005];
int find(int x)
{
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	fa[x]=y;
}

void mintree(int n)
{
	sort(edge.begin(),edge.end(),cmp());
	for(int i=0;i<=n;i++)fa[i]=i;
	int nedge=edge.size();
	int used=0;
	for(int i=0;i<nedge;i++)
	{
		if(find(edge[i].first.first)!=find(edge[i].first.second))
		{
			merge(edge[i].first.first,edge[i].first.second);
			addedge(edge[i].first.first,edge[i].first.second,edge[i].second);
			used++;
		}
		if(used==n-1)break;
	}
}

void dfs(int now,int c)
{
	vis2[now]=true;
	color[now]=c;
	for(vector<pair<int,int> >::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(!vis2[i->first])
		{
			parent[i->first][0]=now;
			height[i->first]=height[now]+1;
			maxn[i->first][0]=i->second;
			dfs(i->first,c);
		}
	}
}

void init_lca(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis2[i])
		{
			height[i]=1;
			dfs(i,i);
		}
	}
	for(int j=1;j<=18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			parent[i][j]=parent[parent[i][j-1]][j-1];
			maxn[i][j]=max(maxn[i][j-1],maxn[parent[i][j-1]][j-1]);
		}
	}
}

int lca(int x,int y)
{
	if(color[x]!=color[y])return -1;
	int maxdis=-100;
	if(height[x]<height[y])swap(x,y);
	for(int i=18;i>=0;i--)
	{
		if(height[parent[x][i]]>=height[y])
		{
			maxdis=max(maxdis,maxn[x][i]);
			x=parent[x][i];
		}
	}
	if(x==y)return maxdis;
	for(int i=18;i>=0;i--)
	{
		if(parent[x][i]!=parent[y][i])
		{
			maxdis=max(maxdis,max(maxn[x][i],maxn[y][i]));
			x=parent[x][i],y=parent[y][i];
		}
	}
	return max(maxdis,max(maxn[x][0],maxn[y][0]));
}

int main()
{
	int P,Q;
	read(H);read(W);read(P);read(Q);
	for(int i=1;i<=H;i++)
	{
		scanf("%s",map[i]+1);
	}
	for(int i=1;i<=P;i++)
	{
		int x,y;
		read(x);read(y);
		city[x][y]=i;
		pcity[i]=make_pair(x,y);
	}
	init_edge(P);
/*	for(auto i:edge)
	{
		printf("(%d,%d)=%d\n",i.first.first,i.first.second,i.second);
	}*/
	mintree(P);
	init_lca(P);
//	read(Q);
	for(int i=0;i<Q;i++)
	{
		int x,y;
		read(x);read(y);
		cout<<lca(x,y)<<"\n";
	}
	return 0;
}
	
} 

int main()
{
	freopen("kettle.in","r",stdin);
	freopen("kettle.out","w",stdout);
	return Solution::main();
}
/*
5 5 4 4
.....
..##.
.#...
..#..
.....
1 1
4 2
3 3
2 5
1 2
2 4
1 3
3 4
*/
