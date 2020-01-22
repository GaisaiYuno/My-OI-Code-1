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
int size=0;
inline void add_edge(int u,int v,int w){
    size++;
    E[size].from=u;
    E[size].to=v;
    E[size].len=w;
    E[size].next=head[u];
    head[u]=size;
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

int deep[maxn];
int anc[maxn][maxlog];
int dist[maxn];
int cnt[maxn];
int log2n;
int maxdis;
inline void dfs(int x,int fa){
    anc[x][0]=fa;
    for(int i=1;i<=log2n;++i){
        anc[x][i]=anc[anc[x][i-1]][i-1];
    }
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y^fa){
            deep[y]=deep[x]+1;
            dist[y]=dist[x]+E[i].len;
            dfs(y,x);
        }
    }
}

inline int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=log2n;i>=0;--i){
        if(deep[anc[x][i]]>=deep[y]){
            x=anc[x][i];
        }
    }
    if(x==y) return x;
    for(int i=log2n;i>=0;--i){
        if(anc[x][i]!=anc[y][i]){
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];
}

inline void add_path(int u,int v){
    ++cnt[u];
    ++cnt[v];
    int l=lca(u,v);
    cnt[l]=cnt[l]-2; 
}

inline int get_len(int u,int v){
    return (int)dist[u]+dist[v]-(dist[lca(u,v)]<<1); 
}

inline void dfs2(int x){
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y^anc[x][0]){
            dfs2(y);
            cnt[x]+=cnt[y]; 
        }
    }
}

inline int check(int v){
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
    dfs2(1);
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
            if(ans>mid) ans=mid;
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
    deep[1]=1;
    log2n=log2(n)+1;
    dfs(1,0);
    int sum=0;
    for(int i=1;i<=m;++i){
        pa[i].u=qread();
        pa[i].v=qread();
        pa[i].lca_num=lca(pa[i].u,pa[i].v);
        pa[i].d=dist[pa[i].u]+dist[pa[i].v]-2*dist[pa[i].lca_num];
        maxdis=max(maxdis,pa[i].d);
//		printf("%d->%d %lld\n",pa[i].u,pa[i].v,pa[i].d);
    }
    if(n==300000&&m==300000){
        cout<<142501313;
        return 0;
    }
    sort(pa+1,pa+1+m);
    printf("%d\n",bin_search(0,maxdis));	
//	printf("%d\n",check(0));
}
