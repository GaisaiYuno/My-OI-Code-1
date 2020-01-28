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
const int mod=1e9+7,maxn=100+10;
int cnt[maxn],sum,ans[maxn];
ll m;
int K;
inline void add(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}
struct Matrix{
	int a[maxn][maxn];
	void clear(int flag=0){
		REP(i,0,K) REP(j,0,K) a[i][j]=0;
		if(flag) REP(i,0,K) a[i][i]=1;
	}
	Matrix operator *(const Matrix &rhs) const{
		Matrix A;A.clear();
		REP(k,0,K) REP(i,0,K) REP(j,0,K) A.a[i][j]=(A.a[i][j]+(ll)a[i][k]*rhs.a[k][j])%mod;
		return A;
	}
	void output(){
		REP(i,0,K) REP(j,0,K) printf("%d%c",a[i][j],j==jend?'\n':' ');
		putchar('\n');
	}
};
void ksm(){
	Matrix x,res;x.clear(1),res.clear(1);
//		x.output();
	REP(i,1,K){
		REP(j,0,K) if(i!=j) REP(k,0,K) add(x.a[k][i],x.a[k][j]);
//		x.output();
	}
	ll y=m/K;
	while(y){
		if(y&1ll) res=res*x;
		x=x*x;
		y>>=1;
	}
	REP(i,0,K) REP(j,0,K) ans[j]=(ans[j]+(ll)cnt[i]*res.a[i][j])%mod;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
#endif
	int n=read();m=readll();K=read();
	cnt[0]=sum=1;
	REP(i,1,n){
		int x=read();
		add(sum,mod-cnt[x]);
		add(cnt[x],sum);
		add(sum,cnt[x]);
	}
	sort(cnt+1,cnt+K+1);
	ksm();
	sum=0;
	REP(i,0,K) add(sum,ans[i]);
	REP(i,1,m%K){
		add(sum,mod-ans[i]);
		add(ans[i],sum);
		add(sum,ans[i]);
	}
	add(sum,mod-1);
	printf("%d\n",sum);
	return 0;
}
