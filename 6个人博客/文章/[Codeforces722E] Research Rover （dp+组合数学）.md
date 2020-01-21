## [Codeforces722E] Research Rover （dp+组合数学）

### 题面

给出一个N*M的方格阵，从(1,1)出发，到(N,M)结束，从(x,y)只能走到(x+1,y)或(x,y+1)。方格阵上还有K个特殊点，初始时给出的分数t每经过一个特殊点就会变成$[\frac{t}{2}]$。求到(N,M)时得分的期望。保证(1,1)和(N,M)不是特殊点。$N,M≤100000，\  K≤2000，\  t≤1000000$

### 分析

考虑根据特殊点dp.把(1,1)和(n,m)也看作特殊点(但分数不除2），把特殊点按x排序。$dp[i][j]$表示经过**至少**j个特殊点(包括i)，到达i的方案数,g(i,j)表示从i点到j点的方案数，

$$g(i,j)=C_{|x_i-x_j|+|y_i-y_j|}^{|x_i-x_j|}$$
我们从(1,1)走到(n,m) 向上走n次，向右走m次，一共(n+m)次，从n+m次中选出n次向上走，就是方案数

$$dp[i][j]=\sum _{u,\\ x_u\leq x_i,\ y_u \leq y_i} (dp[u][j-1] - dp[u][j]) \times g(u,j) $$

$(dp[u][j-1] - dp[u][j])$表示经过j-1个特殊点到u的方案数。

为什么我们定义子状态时用的是至少呢？因为**从u到i的路径上可能有其他特殊点**，导致在u时经过j-1个点，在i时可能就经过j+x (x>=0)个点了，定义为“至少”可以较好的包含这种情况，而需要“正好j个点”的时候只要相减即可。如果我们一开始把子状态定位经过j个点到i的方案数，需要排除中间经过特殊点的情况,容斥起来比较麻烦

最终答案为:

$(C_{n+m}^{m} )^{-1} \times \sum (dp[k][j]-dp[k][j+1]) \times \frac{s}{2^j} $

### 代码

```cpp
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
//	if(m==0||m==n) return 1;
//	if(n<m) return 0;
//不要写这几个判断，常数很大 
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}


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
		s*=2;//多一个点，会多除一次2，所以把s*2来抵消
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
```