/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<utility>
#define maxn 305
using namespace std;
int n,m;
int a[maxn][maxn];
int id[maxn][maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*maxn*4];
int sz=0;
int head[maxn*maxn];
void add_edge(int u,int v){
//	if(ma.count(make_pair(u,v))||ma.count(make_pair(v,u))) return;
//	ma[make_pair(u,v)]=1;
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int valid=0;
const int dirx[8]={-2,-2,-1,-1,1,1,2,2};
const int diry[8]={ 1,-1, 2,-2,-2,2,1,-1};
int vis[maxn*maxn];
int match[maxn*maxn];
int dfs(int x,int tim){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(vis[y]<tim){
			vis[y]=tim;
			if(!match[y]||dfs(match[y],tim)){
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(){
	int ans=0;
	for(int i=1;i<=valid;i++){
		if(dfs(i,i)) ans++;
	}
	return ans/2;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0) id[i][j]=++valid;
		}
	}
	int x,y; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1) continue;
			for(int k=0;k<8;k++){
				x=i+dirx[k];
				y=j+diry[k];
				if(x<1||x>n||y<1||y>m||a[x][y]==1) continue;
				add_edge(id[i][j],id[x][y]);
			}
		}
	}
	printf("%d\n",valid-hungary());
}


