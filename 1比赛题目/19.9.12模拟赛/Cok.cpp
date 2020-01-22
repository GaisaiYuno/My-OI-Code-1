#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define maxk 500000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct disjoint_set{
	int fa[maxn+5];
	int tim[maxn+5];
	int sz[maxn+5];
	int find(int x){
		while(fa[x]!=x) x=fa[x];
		return x;
	}
	int get_deep(int x){
		int ans=0;
		while(fa[x]!=x){
			ans++;
			x=fa[x];
		}
		return ans;
	}
	void merge(int x,int y,int t){
		int fx=find(x);
		int fy=find(y);
		if(sz[fx]>sz[fy]) swap(fx,fy);
		fa[fx]=fy;
		tim[fx]=t;
		sz[fy]+=sz[fx];
	}
	int query(int x,int y){
		if(find(x)!=find(y)) return INF; 
		int ans=0;
		int dx=get_deep(x),dy=get_deep(y);
		if(dx<dy){
			swap(x,y);
			swap(dx,dy);
		}
		while(dx>dy){
			ans=max(ans,tim[x]);
			x=fa[x];
			dx--;
		}
		if(x==y) return ans;
		while(x!=y){
			ans=max(ans,max(tim[x],tim[y]));
			x=fa[x];
			y=fa[y]; 
		} 
		return ans;
	}
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
}S;
int n,m,k;
int g[maxn+5];
struct rec{
	int x;
	int y;
	int tim;
	int id;
	friend bool operator < (rec p,rec q){
		if(p.tim==q.tim) return p.id<q.id;
		else return p.tim<q.tim; 
	}
}q[maxk+5]; 
int main(){
	int u,v;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
	} 
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		S.merge(u,v,i);
	}
	for(int i=1;i<=k;i++){
		scanf("%d %d",&q[i].x,&q[i].y);
		q[i].tim=S.query(q[i].x,q[i].y);
		q[i].id=i; 
	}
	sort(q+1,q+1+k);
	ll ans=0;
	for(int i=1;i<=k;i++){
		if(q[i].tim==INF) continue;
		int x=q[i].x,y=q[i].y;
		int sum=min(g[x],g[y]);
		g[x]-=sum;
		g[y]-=sum;
		ans+=sum*2;
	}
	printf("%lld\n",ans);
}

