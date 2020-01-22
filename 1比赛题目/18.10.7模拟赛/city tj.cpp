#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define zhh 50005
#define inf 0x7fffffffffff
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,head[zhh*2],nt[zhh*2],v[zhh*2],val[zhh],tot,sz;
int pos[zhh],size[zhh],son[zhh],de[zhh],fa[zhh],top[zhh],a[zhh];
ll tr[zhh*4],tr1[zhh*4],posx[zhh*4],posn[zhh*4],add[zhh*4];
ll xl[zhh],yl[zhh],xr[zhh],yr[zhh];
struct node{
	ll ma,mi,posx,posn;
};
void ad(int x,int y){
	v[++tot]=y;nt[tot]=head[x];head[x]=tot;
}
void dfs1(int x,int pr){
	fa[x]=pr;
	size[x]=1;
	for(int i=head[x];i;i=nt[i]){
		if(v[i]==pr) continue;
		de[v[i]]=de[x]+1;
		dfs1(v[i],x);
		size[x]+=size[v[i]];
		if(size[son[x]]<size[v[i]]){
			son[x]=v[i];
		}
	}
}
void dfs(int x,int chain){
	pos[x]=++sz;
	a[sz]=val[x];
	top[x]=chain;
	if(!son[x]) return;
	dfs(son[x],chain);
	for(int i=head[x];i;i=nt[i]){
		if(v[i]==fa[x]) continue;
		if(v[i]==son[x]) continue;
		dfs(v[i],v[i]);
	}
}
void zgx(int c){
	tr[c]=max(tr[c*2],tr[c*2+1]);
	tr1[c]=min(tr1[c*2],tr1[c*2+1]);
	posx[c]=max(posx[c*2],posx[c*2+1]);
	posx[c]=max(posx[c],tr[c*2+1]-tr1[c*2]);
	posn[c]=max(posn[c*2],posn[c*2+1]);
	posn[c]=max(posn[c],tr[c*2]-tr1[c*2+1]);
}
void build(int c,int l,int r){
	if(l==r){
		tr[c]=tr1[c]=1LL*a[l];
		posx[c]=posn[c]=0;
	}
	else{
		int mid=(l+r)/2;
		build(c*2,l,mid);
		build(c*2+1,mid+1,r);
		zgx(c);
	}
}
void spread(int c){
	if(add[c]){
		tr[c*2]+=add[c];
		tr[c*2+1]+=add[c];
		tr1[c*2]+=add[c];
		tr1[c*2+1]+=add[c];
		add[c*2]+=add[c];
		add[c*2+1]+=add[c];
		add[c]=0;
	}
}
void ad1(int c,int l,int r,int L,int R,ll v){
	if(L<=l&&r<=R){
		tr[c]+=v;
		tr1[c]+=v;
		add[c]+=v;
	}
	else{
		int mid=(l+r)/2;
		spread(c);
		if(L<=mid) ad1(c*2,l,mid,L,R,v);
		if(R>mid) ad1(c*2+1,mid+1,r,L,R,v);
		zgx(c);
	}
}
node ask(int c,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		node a;
		a.ma=tr[c];
		a.mi=tr1[c];
		a.posx=posx[c];
		a.posn=posn[c];
		return a;
	}
	int mid=(l+r)/2;
	spread(c);
	node a,t,t1;
	bool f=0,f1=0;
	a.ma=0,a.mi=inf,a.posx=0,a.posn=0;
	t.ma=0,t.mi=inf,t.posx=0,t.posn=0;
	t1.ma=0,t1.mi=inf,t1.posx=0,t1.posn=0;
	if(L<=mid) t=ask(c*2,l,mid,L,R),f=1;
	if(R>mid) t1=ask(c*2+1,mid+1,r,L,R),f1=1;
	a.ma=max(t.ma,t1.ma);
	a.mi=min(t.mi,t1.mi);
	a.posx=max(t.posx,t1.posx);
	if(f&&f1) a.posx=max(a.posx,t1.ma-t.mi);
	a.posn=max(t.posn,t1.posn);
	if(f&&f1) a.posn=max(a.posn,t.ma-t1.mi);
	return a;
}
void solve(int x,int y,ll z){
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]]) swap(x,y);
		ad1(1,1,n,pos[top[x]],pos[x],z);
		x=fa[top[x]];
	}
	if(de[x]>de[y]) swap(x,y);
	ad1(1,1,n,pos[x],pos[y],z);
}
ll solve1(int x,int y){
	int hh=0,hh1=0;
	ll ans=0;
	while(top[x]!=top[y]){
		if(de[top[x]]>de[top[y]]){
			node t=ask(1,1,n,pos[top[x]],pos[x]);
			ans=max(ans,t.posn);
			xl[++hh]=t.mi;
			xr[hh]=t.ma;
			x=fa[top[x]];
		}
		else{
			node t=ask(1,1,n,pos[top[y]],pos[y]);
			ans=max(ans,t.posx);
			yl[++hh1]=t.mi;
			yr[hh1]=t.ma;
			y=fa[top[y]];
		}
	}
	if(de[x]>de[y]){
		swap(x,y);
		node t=ask(1,1,n,pos[x],pos[y]);
		ans=max(ans,t.posn);
		xl[++hh]=t.mi;
		xr[hh]=t.ma;
	}
	else{
		node t=ask(1,1,n,pos[x],pos[y]);
		ans=max(ans,t.posx);
		yl[++hh1]=t.mi;
		yr[hh1]=t.ma;
	}
	fd(i,hh1,1){
		xl[++hh]=yl[i],xr[hh]=yr[i];
	}
	ll minn=inf;
	fu(i,1,hh){
		ans=max(ans,xr[i]-minn);
		minn=min(minn,xl[i]);
	}
	ll maxn=0;
	fd(i,hh,1){
		ans=max(ans,maxn-xl[i]);
		maxn=max(maxn,xr[i]);
	}
	return ans;
}
int fp(int x) {
	if(x>9) fp(x/10);
	putchar(x%10+'0');
}
int main(){

	n=read();
	fu(i,1,n){
		val[i]=read();
	}	
	fu(i,1,n-1){
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	dfs1(1,0);
	dfs(1,1);
	build(1,1,n);
	m=read();
	fu(i,1,m){
		ll x=read(),y=read(),z=read();
		fp(solve1(x,y));
		puts("");
		solve(x,y,z);
	}
}
