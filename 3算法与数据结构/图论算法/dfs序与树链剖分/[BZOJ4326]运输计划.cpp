#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define maxn 300005
#define INF 0x7fffffff
#define maxlog 32
using namespace std;
inline int qread(){
    int x=0,sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar(); 
    } 
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar(); 
    }
    return x*sign;
} 
int n,m;
struct edge{
    int from;
    int to;
    int len;
    int next;
}E[maxn<<1];
int head[maxn];
int esize=0;
inline void add_edge(int u,int v,int w){
    esize++;
    E[esize].from=u;
    E[esize].to=v;
    E[esize].len=w;
    E[esize].next=head[u];
    head[u]=esize;
}
struct route{
    int u;
    int v;
    int lca_num;
    int d;
    friend bool operator < (route a,route b){
        return a.d>b.d;
    }
}pa[maxn];

int fa[maxn],son[maxn],sz[maxn],top[maxn];
int deep[maxn];
int dist[maxn];
int cnt[maxn];
int maxdis;
void dfs1(int x,int f){
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dist[y]=dist[x]+E[i].len;
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
} 
void dfs2(int x,int t){
	top[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
} 
int lca(int x,int y){//树剖求lca，卡常 
	while(top[x]!=top[y]){
		if(deep[top[x]]>=deep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	} 
	if(deep[x]<deep[y]) return x;
	else return y;
}

inline void add_path(int u,int v){
    cnt[u]++;
    cnt[v]++;
    int l=lca(u,v);
    cnt[l]-=2; 
}

inline int get_len(int u,int v){
    return dist[u]+dist[v]-(dist[lca(u,v)]<<1); 
}

void dfs3(int x){
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=fa[x]){
            dfs3(y);
            cnt[x]+=cnt[y]; 
        }
    }
}

int check(int v){
//	memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;++i) cnt[i]=0;
    int x=0;
    int maxd=0;
    for(int i=1;i<=m;++i){
        if(pa[i].d>v){
            x++;
            maxd=max(pa[i].d,maxd);
            cnt[pa[i].u]++;
            cnt[pa[i].v]++;
            cnt[pa[i].lca_num]-=2;
        }
        else break;
    }
    dfs3(1);
    int p,q;
    for(int i=1;i<=n;++i){
        p=E[i*2-1].from;
        q=E[i*2-1].to;
        if(deep[p]>deep[q]) swap(p,q);
        if(cnt[q]==x){
            if(maxd-E[i*2-1].len<=v) return 1;
        }
    }
    return 0;
}

int bin_search(int l,int r){
    int ans=INF;
    int mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return ans;
}
int main(){
//	freopen("transport20.in","r",stdin);
    int u,v,w;
    n=qread();
    m=qread(); 
//	printf("%d %d\n",n,m);
    for(int i=1;i<n;++i){
        u=qread();
        v=qread();
        w=qread(); 
        add_edge(u,v,w);
        add_edge(v,u,w); 
    }

    dfs1(1,0);
    dfs2(1,1);
    int sum=0;
    for(int i=1;i<=m;++i){
        pa[i].u=qread();
        pa[i].v=qread();
        pa[i].lca_num=lca(pa[i].u,pa[i].v);
        pa[i].d=dist[pa[i].u]+dist[pa[i].v]-2*dist[pa[i].lca_num];
        maxdis=max(maxdis,pa[i].d);
    }
    sort(pa+1,pa+1+m);//把路径按长度从大到小排序，这样只要遍历到<mid的路径就直接break 
    printf("%d\n",bin_search(0,maxdis));	
}
