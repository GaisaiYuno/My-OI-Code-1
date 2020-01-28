#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10,inf=1e9,size=maxn*40;
int n,q,type,a[maxn],lastans,r,k,p[maxn],fa[20][maxn],dep[maxn],rt[maxn];
vector<int> g[maxn];

namespace segt{
	int cnt,sum[size],lson[size],rson[size];
	inline int newnode(int x){
		++cnt;
		sum[cnt]=sum[x];
		lson[cnt]=lson[x];rson[cnt]=rson[x];
		return cnt;
	}
	inline void push_up(int rt){
		sum[rt]=sum[lson[rt]]+sum[rson[rt]];
	}
	int insert(int rt,int l,int r,int pos){
		rt=newnode(rt);
		++sum[rt];
		if(l==r)
			return rt;
		int mid=l+r>>1;
		if(pos<=mid)
			lson[rt]=insert(lson[rt],l,mid,pos);
		else
			rson[rt]=insert(rson[rt],mid+1,r,pos);
		push_up(rt);
		return rt;
	}
	int queryl(int rt1,int rt2,int l,int r,int y){
		if(sum[rt1]==sum[rt2])
			return 0;
		if(l==r)
			return l;
		int mid=l+r>>1;
		if(y<=mid)
			return queryl(lson[rt1],lson[rt2],l,mid,y);
		else{
			int tmp=queryl(rson[rt1],rson[rt2],mid+1,r,y);
			if(tmp)
				return tmp;
			else
				return queryl(lson[rt1],lson[rt2],l,mid,mid);
		}
	}
	int queryr(int rt1,int rt2,int l,int r,int x){
		if(sum[rt1]==sum[rt2])
			return 0;
		if(l==r)
			return l;
		int mid=l+r>>1;
		if(x>mid)
			return queryr(rson[rt1],rson[rt2],mid+1,r,x);
		else{
			int tmp=queryr(lson[rt1],lson[rt2],l,mid,x);
			if(tmp)
				return tmp;
			else
				return queryr(rson[rt1],rson[rt2],mid+1,r,mid+1);
		}
	}
}
void dfs(int pos){
	for(int i=1;i<20;++i)
		fa[i][pos]=fa[i-1][fa[i-1][pos]];
	dep[pos]=dep[fa[0][pos]]+1;
	rt[pos]=segt::insert(rt[fa[0][pos]],1,inf,a[pos]);
	for(int i=0;i<g[pos].size();++i)
		if(g[pos][i]!=fa[0][pos]){
			fa[0][g[pos][i]]=pos;
			dfs(g[pos][i]);
		}
}
inline int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;~i;--i)
		if(dep[fa[i][u]]>=dep[v])
			u=fa[i][u];
	if(u==v)
		return u;
	for(int i=19;~i;--i)
		if(fa[i][u]!=fa[i][v])
			u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}

int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d%d%d",&n,&q,&type);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	while(q--){
		scanf("%d%d",&r,&k);
		for(int i=1;i<=k;++i){
			scanf("%d",&p[i]);
			p[i]=(p[i]-1+lastans*type)%n+1;
		}
		int f=p[1],res=inf;
		for(int i=2;i<=k;++i)
			f=lca(f,p[i]);
		f=fa[0][f];
		for(int i=1,tmp;i<=k;++i){
			tmp=segt::queryl(rt[f],rt[p[i]],1,inf,r);
			if(tmp&&r-tmp<res)
				res=r-tmp;
			tmp=segt::queryr(rt[f],rt[p[i]],1,inf,r);
			if(tmp&&tmp-r<res)
				res=tmp-r;
		}
		printf("%d\n",res);
		lastans=res;
	}
	return 0;
}
