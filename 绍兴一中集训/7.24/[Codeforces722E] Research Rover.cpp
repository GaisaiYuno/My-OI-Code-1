#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxk 3000
#define maxn 100000
#define maxlogs 32
#define mod 1000000007
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
typedef long long ll;
int n,m,k,s;
int log2s;

struct point{
	int x;
	int y;
	point(){
		
	}
	point(int _x,int _y){
		x=_x;
		y=_y;
	}
	friend bool operator < (point p,point q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	} 
}a[maxk+5];

inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}
ll fact[maxn*2+5],invfact[maxn*2+5];
inline ll C(int n,int m){
	if(m==0||m==n) return 1;
	if(n<m) return 0;
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}

//inline ll calc(point p,point q){
//	int n=q.x-p.x;
//	if(n<0) n=-n;
//	int m=q.y-p.y;
//	if(m<0) m=-m;
//	return C(n+m,n);
//}
 
inline ll calc(point p,point q){
	return C(q.x-p.x+q.y-p.y,q.x-p.x);
}

ll dp[maxk+5][maxlogs+5];//dp[i][j]表示当前到第i个点，经过j个点 
int main(){
	qread(n);
	qread(m);
	qread(k);
	qread(s);
	ini_fact(n+m);
	for(int i=1;i<=k;i++){
		qread(a[i].x);
		qread(a[i].y);
	}
	sort(a+1,a+1+k);
	//加入虚拟点(1,1)(n,m) 
	if(a[1].x!=1||a[1].y!=1){
		s*=2;
		a[++k]=point(1,1);
	}
	if(a[k].x!=n||a[k].y!=m) a[++k]=point(n,m); 
	else s-=s/2;
	log2s=log2(s)+1;
	sort(a+1,a+1+k);
	dp[1][0]=1;
	for(int i=2;i<=k;i++){
		dp[i][1]=calc(a[1],a[i]);
		for(int j=2;j<=log2s;j++){
			for(int u=1;u<i;u++){
				if(a[u].y<=a[i].y&&a[u].x<=a[i].x){
					dp[i][j]+=dp[u][j-1]*calc(a[u],a[i])%mod;
					dp[i][j]=(dp[i][j]+mod)%mod;
					dp[i][j]-=dp[u][j]*calc(a[u],a[i])%mod;
					dp[i][j]=(dp[i][j]+mod)%mod;
				}
			}
		}
	} 
	ll ans=0;
	for(int i=1;i<=log2s;i++){
		s-=s/2;
		ans=(ans+(dp[k][i]-dp[k][i+1]+mod)*s%mod)%mod;
	}
	ans=ans*inv(calc(a[1],a[k]))%mod;
	printf("%I64d\n",ans);
} 
