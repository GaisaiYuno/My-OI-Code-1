#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
typedef long double ll;
int n;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=0;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

ll c[maxn+5];
ll lenf[maxn+5];
ll sumc[maxn+5];
ll f1[maxn+5];
ll f2[maxn+5];
void dfs1(int x,int fa){
	sumc[x]=c[x];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			lenf[y]=E[i].len;
			dfs1(y,x);
			sumc[x]+=sumc[y];
			f1[x]+=f1[y]+sumc[y]*lenf[y];
			f2[x]+=f2[y]+2*lenf[y]*f1[y]+lenf[y]*lenf[y]*sumc[y];
		}
	}
}

ll g1[maxn+5];
ll g2[maxn+5];
void dfs2(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			g1[y]=g1[x]-(f1[y]+sumc[y]*lenf[y])+lenf[y]*(sumc[1]-sumc[y])+f1[y];
			g2[y]=g2[x]-(f2[y]+2*lenf[y]*f1[y]+lenf[y]*lenf[y]*sumc[y])
				  +2*lenf[y]*(g1[x]-(f1[y]+sumc[y]*lenf[y]))
				  +lenf[y]*lenf[y]*(sumc[1]-sumc[y])+f2[y];
			dfs2(y,x);
		}
	}
}

int main(){
	freopen("problem3.in","r",stdin);
	freopen("problem3.out","w",stdout);
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%Lf",&c[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs1(1,0);
	g1[1]=f1[1];
	g2[1]=f2[1];
	dfs2(1,0);
	ll ans=-1;
	for(int i=1;i<=n;i++){
		if(ans==-1||g2[i]<ans) ans=g2[i];
	}
	printf("%.5Lf\n",ans);
}
