#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=888;
struct edge{int to,next,id,w;}G[maxn*10];
struct edges{int a,b,w,f;}e[maxn*10];
int n,m,ans=0,h[maxn],q[maxn],fa[maxn][10];
int mp[maxn][maxn],lx[maxn],ly[maxn],ind[maxn];
int girl[maxn],sta[maxn],tot=0,dep[maxn];
bool visx[maxn],visy[maxn],vis[maxn];
 
void get_dep(){
	int head=1,t=1; q[head]=1; vis[1]=1;
	while (head<=t){
		int u=q[head++];
		for (int i=h[u];i;i=G[i].next){
			int v=G[i].to;
			if (vis[v]) continue;
			vis[v]=1; fa[v][0]=u;
			dep[v]=dep[u]+1; q[++t]=v;
			ind[v]=G[i].id;
		}
	}
}
 
int query(int a,int b){
	if (dep[a]<dep[b]) swap(a,b);
	int t=dep[a]-dep[b];
	for (int i=8;~i;--i)
	    if (t&(1<<i)) a=fa[a][i];
	if (a==b) return a;
	for (int i=8;~i;--i)
	    if (fa[a][i]!=fa[b][i])
			a=fa[a][i], b=fa[b][i];
	return fa[a][0];
}
 
void add(int x,int y,int id){
	G[++tot].to=y; G[tot].next=h[x]; h[x]=tot; G[tot].id=id;
	G[++tot].to=x; G[tot].next=h[y]; h[y]=tot; G[tot].id=id;
}
 
void build(int x,int f,int id,int w){
	while (x!=f)
		{
			printf("debug%d %d\n",ind[x],id);
		mp[ind[x]][id]=max(0,e[ind[x]].w-w);
		x=fa[x][0];}
}
 
bool find(int x){
	visx[x]=1;
	for (int y=1;y<=m;++y)
	    if (!visy[y]){
			int tmp=lx[x]+ly[y]-mp[x][y];
			if (!tmp){
				visy[y]=1;
				if (!girl[y]||find(girl[y])){
					girl[y]=x; return 1;}
			}else sta[y]=min(sta[y],tmp);
	    }return 0;
}
 
void KM(){
	memset(lx,-63,sizeof(lx));
	memset(ly,0,sizeof(ly));
	memset(girl,0,sizeof(girl));
	for (int i=1;i<=m;++i)
	    for (int j=1;j<=m;++j)
	        lx[i]=max(lx[i],mp[i][j]);
	for (int x=1;x<=m;++x){
		memset(sta,127/3,sizeof(sta));
		while (true){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if (find(x)) break;
			int d=0x7fffffff/3;
			for (int i=1;i<=m;++i)
			    if (!visy[i]) d=min(d,sta[i]);
			for (int i=1;i<=m;++i){
				if (visx[i]) lx[i]-=d;
				if (visy[i]) ly[i]+=d;
				else sta[i]-=d;
			}
		}
	}
	for (int i=1;i<=m;++i) ans+=mp[girl[i]][i];
}
 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	    scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	for (int j=1;j<n;++j){
		int x,y; scanf("%d%d",&x,&y);
		for (int i=1;i<=m;++i)
		    if ((e[i].a==x&&e[i].b==y)||(e[i].a==y&&e[i].b==x)){
				e[i].f=1; add(x,y,i);
		    }
	}
	get_dep();
	for (int j=1;j<=8;++j)
	    for (int i=1;i<=n;++i)
	        fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=m;++i)
	    if (!e[i].f){
			int lca=query(e[i].a,e[i].b);
			build(e[i].a,lca,i,e[i].w);
			build(e[i].b,lca,i,e[i].w);
	    }
	KM(); printf("%d",ans);
}


