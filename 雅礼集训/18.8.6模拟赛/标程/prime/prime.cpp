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
const int maxn=1e7+10;
int prime[maxn],tmp;
bool p[maxn],isprime[maxn];
void init(int n){
	REP(i,2,n){
		if(!isprime[i]) prime[++tmp]=i;
		REP(j,1,tmp){
			if((ll)i*prime[j]>n) break;
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
#endif
	ll L=readll(),R=readll();
	int k=read();
	init(min(maxn-10,k));
	REP(i,1,tmp){
		int u=prime[i];
		for(ll j=max((L-1)/u+1,2ll);j*u<=R;++j)
			p[j*u-L]=1;
	}
	ll ans=0;
	for(ll i=L;i<=R;++i) if(!p[i-L]) ans^=i;
	printf("%lld\n",ans);
	return 0;
}
