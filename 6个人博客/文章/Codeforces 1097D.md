### 题目
[传送门](http://codeforces.com/problemset/problem/1097/D)
### 分析
考虑$n=p^q$且p为质数的情况
设dp[i][j]表示经过i次变化后数为$p^j$的概率
则初始值dp[0][q]=1
状态转移方程为$dp[i][j]=\sum{}\frac{1}{u+1}dp[i-1][u],u\in[j,q]$
最终的期望值$E(p^q)=\sum dp[k][j] ·p^j ,j \in [0,q]$
那么如果n不是某个质数的q次方呢
把n分解质因数，$n={p_1}^{q_1}{p_2}^{q_2} \dots {p_n}^{q_n}$
对于每一个${p_i}^{q_i}$,求出期望再相乘即可
注意逆元最好要预处理,否则常数略大,总时间复杂度$O(\sqrt n+k \log n)$

### 代码
```cpp
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 205
#define maxk 10005
#define mod 1000000007
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

inline long long inverse(long long x){
	return fast_pow(x,mod-2);
}

long long n,k;
int cnt=0;
long long p[maxn];
int a[maxn];
void div(long long x){
	long long i=2;
	while(i*i<=x){
		if(x%i){
			i++;
		}else{
			p[++cnt]=i;
			while(x%i==0){
				a[cnt]++;
				x/=i;
			}
		} 
	}
	if(x!=1){
		p[++cnt]=x;
		a[cnt]=1;
	}
}

long long inv[maxn];
long long dp[maxn];
long long dp_solve(long long p,int q){
	memset(dp,0,sizeof(dp));
	dp[q]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=q;j++){
			long long tmp=0;
			for(int u=j;u<=q;u++){
				tmp=(tmp+dp[u]*inv[u+1]%mod)%mod;
			}
			dp[j]=tmp;
		}
	}
	long long ans=0;
	for(int i=0;i<=q;i++){
		ans+=fast_pow(p,i)*dp[i]%mod;
		ans%=mod;
	}
	return ans;
}

int main(){
	scanf("%I64d %d",&n,&k);
	div(n);
	long long ans=1;
	for(int i=0;i<=100;i++){
		inv[i]=inverse(i); 
	}
	for(int i=1;i<=cnt;i++){
		ans*=dp_solve(p[i],a[i]);
		ans%=mod;
	}
	
	printf("%I64d\n",ans%mod);
}
```