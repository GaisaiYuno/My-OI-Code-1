#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fst[maxn],lst[maxn<<1],to[maxn<<1],ans[maxn],e;
int n,m,q;
inline void add(int x,int y){
	to[++e]=y,lst[e]=fst[x],fst[x]=e;
}
int ls[maxn<<5],rs[maxn<<5],lx[maxn<<5],rx[maxn<<5],mx[maxn<<5],root[maxn],cnt;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void pushup(int rt,int l,int r){
	int mid=(l+r)>>1;
	if(ls[rt]&&rs[rt])lx[rt]=lx[ls[rt]],rx[rt]=rx[rs[rt]],mx[rt]=max(max(mx[ls[rt]],mx[rs[rt]]),rx[ls[rt]]+lx[rs[rt]]);
	else if(ls[rt])lx[rt]=lx[ls[rt]],rx[rt]=rx[ls[rt]]+r-mid,mx[rt]=mx[ls[rt]];
	else if(rs[rt])lx[rt]=lx[rs[rt]]+mid-l+1,rx[rt]=rx[rs[rt]],mx[rt]=mx[rs[rt]];
}
inline void update(int &rt,int l,int r,int x){
	if(!rt)rt=++cnt;
	if(l==r){
		lx[rt]=rx[rt]=mx[rt]=0;
		return;
	}int mid=(l+r)>>1;
	if(x<=mid)update(ls[rt],l,mid,x);
	else update(rs[rt],mid+1,r,x);
	pushup(rt,l,r); 
}
inline int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	int mid=(l+r)>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	pushup(x,l,r);
	return x;
}
vector<int>v[maxn];
inline void dfs(int x,int f){
	for(register int i=fst[x];i;i=lst[i]){
		int u=to[i];
		if(u==f)continue;
		dfs(u,x);
		root[x]=merge(root[x],root[u],1,m);
	}int sz=v[x].size();
	for(register int i=0;i<sz;++i)update(root[x],1,m,v[x][i]);
	if(!root[x])ans[x]=-1;
	else ans[x]=max(mx[root[x]],lx[root[x]]+rx[root[x]]);
}
inline void solve(){
	n=read(),m=read(),q=read();
	int x,y;
	for(register int i=1;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	while(q--)x=read(),y=read(),v[x].push_back(y);
	dfs(1,0);
}
int main(){
	solve();
	for(int i=1;i<=n;i++) printf("%d ",root[i]);
	for(register int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}


