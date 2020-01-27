#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#include<algorithm>
#define maxn 100005
#define INF 0x3f3f3f3f 
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int ptr=0;
int head[maxn];
void add_edge(int u,int v,int w){
	ptr++;
	E[ptr].from=u;
	E[ptr].to=v;
	E[ptr].len=w;
	E[ptr].next=head[u];
	head[u]=ptr;
}

int sz[maxn];
int maxsz[maxn]; 
int used[maxn];
int root;
int tree_sz;
int minv;
void get_root(int x,int fa){
    sz[x]=1;
    maxsz[x]=0;
    for(int i=head[x];i;i=E[i].next){
    	int y=E[i].to;
    	if(y==fa||used[y]) continue;
    	get_root(y,x);
    	sz[x]+=sz[y];
		maxsz[x]=max(sz[y],maxsz[x]); 
	}
	maxsz[x]=max(maxsz[x],tree_sz-maxsz[x]);
	if(maxsz[x]<minv){
		minv=maxsz[x];
		root=x;
	}
}

vector<int>dis;
void get_dis(int x,int fa,int d){
	dis.push_back(d);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(used[y]||y==fa) continue;
		get_dis(y,x,d+E[i].len);
	}
}

int calc(int x,int len){
	dis.clear();
	get_dis(x,0,len);
	sort(dis.begin(),dis.end());
	int l=0,r=dis.size()-1;
	int tmp=0;
	while(l<=r){
		if(dis[l]+dis[r]<=k){
			tmp+=r-l;
			l++; 
		}else r--;
	}
	return tmp;
}

long long ans=0; 
void divide(int r){
	ans=ans+calc(r,0);
	used[r]=1;
	for(int i=head[r];i;i=E[i].next){
		int y=E[i].to;
		if(used[y]) continue;
		ans=ans-calc(y,E[i].len);
		tree_sz=sz[y];
		root=0;
		minv=INF;
		get_root(y,0);
		divide(root);
	}
}

void ini(){
	memset(head,0,sizeof(head));
	memset(E,0,sizeof(E));
	ptr=0;
	ans=0;
	memset(used,0,sizeof(used));
}
int main(){
	int u,v,w;
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n==0&&k==0) break;
		ini();
		for(int i=1;i<n;i++){
			scanf("%d %d %d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		minv=INF;
		tree_sz=n;
		get_root(1,0);
		divide(root);
		printf("%lld\n",ans);
	}
}
