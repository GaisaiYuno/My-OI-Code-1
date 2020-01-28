#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=5e5+10,mod=998244353;
int p[maxn],t,n;
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
struct Tree{
	int k1,k2,b1,b2;
}T[maxn<<2];
Tree merge(Tree L,Tree R){
	Tree res;
	res.k1=(ll)L.k1*R.k1%mod;
	res.b1=(R.b1+(ll)R.k1*L.b1)%mod;
	res.k2=(L.k2+(ll)R.k2*L.k1)%mod;
	res.b2=(L.b2+(ll)R.k2*L.b1+(ll)R.b2)%mod;
	return res;
}
struct Segment_tree{
	void push_up(int x){
		T[x]=merge(T[x<<1],T[x<<1|1]);
	}
	void update(int x,int L,int R,int q){
		if(L==R){
			T[x].k1=((ll)(mod+1-p[L])*t+p[L])%mod;
			T[x].b1=T[x].k2=p[L];
			T[x].b2=0;
			return;
		}
		int Mid=(L+R)>>1;
		if(q<=Mid) update(x<<1,L,Mid,q);
		else update(x<<1|1,Mid+1,R,q);
		push_up(x);
	}
	Tree query(int x,int L,int R,int ql,int qr){
		if(ql<=L && R<=qr) return T[x];
		int Mid=(L+R)>>1;
		if(qr<=Mid) return query(x<<1,L,Mid,ql,qr);
		if(ql>Mid) return query(x<<1|1,Mid+1,R,ql,qr);
		return merge(query(x<<1,L,Mid,ql,qr),query(x<<1|1,Mid+1,R,ql,qr));
	}
}Seg;
inline void add(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}
struct szsz{
	int c[maxn];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline int sum(int x){
		int res=0;
		while(x){
			add(res,c[x]);
			x-=lowbit(x);
		}
		return res;
	}
	inline void Add(int x,int y){
		while(x<=n){
			add(c[x],y);
			x+=lowbit(x);
		}
	}
	inline int query(int l,int r){
		return (sum(r)-sum(l-1)+mod)%mod;
	}
}bit;
int main(){
#ifndef ONLINE_JUDGE
	freopen("omeed.in","r",stdin);
	freopen("omeed.out","w",stdout);
#endif
	int num=read();
	n=read();
	int q=read(),ta=read(),tb=read(),A=read(),B=read();
	t=(ll)ta*ksm(tb,mod-2)%mod;
	REP(i,1,n){
		int x=read(),y=read();
		p[i]=(ll)x*ksm(y,mod-2)%mod;
		Seg.update(1,1,n,i);
		bit.Add(i,p[i]);
	}
	while(q--){
		int ty=read();
		if(ty==0){
			int u=read(),x=read(),y=read();
			x=(ll)x*ksm(y,mod-2)%mod;
			bit.Add(u,mod-p[u]);
			p[u]=x;
			Seg.update(1,1,n,u);
			bit.Add(u,x);
		}
		else{
			int l=read(),r=read();
			Tree u=Seg.query(1,1,n,l,r);
			int res=(ll)A*bit.query(l,r)%mod;
			res=(res+(ll)B*(u.b2+bit.query(l,r)))%mod;
			printf("%d\n",res);
		}
	}
	return 0;
}
