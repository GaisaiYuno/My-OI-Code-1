## [BZOJ 3512]DZY Loves Math IV(杜教筛)

### 题面

求$\sum _{i=1}^n\sum _{j=1}^m\varphi (ij)$

$n \leq 10^5,m \leq 10^9$

### 分析

首先要记住欧拉函数的一个性质

> 若$n,m$的质因子种类相同，只是指数不同，则$\varphi(nm)=m\varphi(n)$
>
> 证明:
>
> 注意到欧拉函数的公式$\varphi(n)=n\prod_{i=1}^{\omega(n)} (1-\frac{1}{p_i})$
>
> 设n的质因数分解式为$\prod_{i=1}^k p_i^{a_i}$,发现指数$a_i$对欧拉函数公式里连乘那部分没有影响.而n只对前面部分有影响
>
> 因此$\varphi(nm)=nm \prod_{i=1}^{k} (1-\frac{1}{p_i})$，$\varphi(m)=m\prod_{i=1}^{k} (1-\frac{1}{p_i})$

观察到n比较小，可以枚举。

定义$S(n,m)=\sum_{j=1}^m\varphi (ni)$

设n的质因数分解式为$\prod_{i=1}^k p_i^{a_i}$,于是令$n'=\prod_{i=1}^k p_i,n''=\frac{n}{n'}$,则$\varphi(n)=n''\varphi(n')$同理，$\varphi(ni)=n''\varphi(n'i)$

那么

$$\begin{aligned}
S(n,m)&=n''\sum _{i=1}^m\varphi (n'i) \\
&=n''\sum _{i=1}^m\varphi (\frac{n'}{\gcd(n',i)} \times \gcd(n',i) \times i) \end{aligned}$$ 

注意到$\frac{n'}{\gcd(n',i)}$与$\gcd(n',i) \times i$互质，且欧拉函数为积性函数

$$\begin{aligned} &=n''\sum _{i=1}^m\varphi (\frac{n'}{\gcd(n',i)}) \times \varphi(\gcd(n',i) \times i) )\end{aligned}$$

又注意到$gcd(n',i)$包含的质因子是$i$质因子的子集，因此$\gcd(n',i) \times i$包含的质因子的种类与$i$相同,$\varphi(\gcd(n',i) \times i)=\varphi(i) \times \gcd(n',i)$

$$\begin{aligned} &=n''\sum _{i=1}^m\varphi (\frac{n'}{\gcd(n',i)}) \times \varphi(i) \times \gcd(n',i)\end{aligned}$$

又因为狄利克雷卷积里的一个常用结论$ \varphi*I =id$,即$\sum_{d|n} \varphi(d)=n$

$$ \begin{aligned} &=n''\sum _{i=1}^m\varphi (\frac{n'}{gcd(i,n')})\varphi (i)\sum _{d|gcd(i,n')}\varphi (d) \end{aligned}$$

又因为$\frac{n'}{gcd(i,n')} $一定不包含$\gcd(i,n')$的质因子($n'$的质因数分解里每个质因子的指数都为1,gcd里的质因子一定被除干净了)，因此$\frac{n'}{gcd(i,n')} $与$\gcd(i,n')$互质，也一定与它的约数$d$互质。

$$\begin{aligned} \varphi (\frac{n'}{gcd(i,n')}) \times \varphi(d)=\varphi (\frac{n'd}{gcd(i,n')})=\varphi(\frac{n'}{\frac{\gcd(i,n')}{d}}) \end{aligned}$$

代回原式

$$\begin{aligned} &=n''\sum _{i=1}^m\varphi (i)\sum _{d|gcd(i,n')}\varphi(\frac{n'}{\frac{\gcd(i,n')}{d}}) \end{aligned}$$

如果把$\frac{\gcd(i,n')}{d}$换成$d$,发现其实只是求和的顺序变了，答案不变

因此

$$\begin{aligned} &=n''\sum _{i=1}^m\varphi (i)\sum _{d|gcd(i,n')}\varphi(\frac{n'}{d})  \\ &=n''\sum _{i=1}^m\varphi (i)\sum _{d|i,d|n'}\varphi(\frac{n'}{d})\end{aligned} $$

改变求和顺序，先枚举$d$再枚举$d$的倍数,把原来的$i$替换成$di(i \leq \lfloor \frac{m}{d} \rfloor)$

$$\begin{aligned}&=n''\sum _{d|n'} \varphi (\frac{n'}{d})\sum _{i=1}^{\lfloor\frac{m}{e}\rfloor}\varphi (di) \\
&=n''\sum _{d|n'} \varphi (\frac{n'}{d})S(d,\lfloor\frac{m}{d}\rfloor) \\
\end{aligned}$$

总结一下：

$$\begin{aligned}
S(n,m)&=n''\sum _{d|n'} \varphi (\frac{n'}{d})S(d,\lfloor\frac{m}{d}\rfloor) 
\end{aligned}$$

可以暴力枚举$n'$的约数，记忆化搜索求解。递归到$n=1$时$S(n,m)=\sum_{i=1}^m \varphi(i)$,直接杜教筛求解，复杂度$O(m^{\frac{2}{3}})$.顺便线性筛出$\varphi(\frac{n'}{d})$的值，以及每个数n对应的$n'$

总复杂度$O(n\sqrt m + m^{\frac{2}{3}})$???，反正跑得过就对了

###　代码

 ```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map> 
#define maxn 3000000
#define mod 1000000007
using namespace std;
typedef long long ll;
int cnt;
int prime[maxn+5];
int vis[maxn+5];
int low[maxn+5];//x的质因子各一个乘起来得到的数，就是n'
int phi[maxn+5];
ll sum_phi[maxn+5];
void sieve(int n){
	phi[1]=1;
	vis[1]=1;
	low[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
			low[i]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j] ;
				low[i*prime[j]]=low[i];
				break;
			}else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
				low[i*prime[j]]=low[i]*prime[j];
			} 
		}
	}
	for(int i=1;i<=n;i++) sum_phi[i]=(sum_phi[i-1]+phi[i])%mod;
}

map<int,ll>ans[maxn+5],ans_phi;
ll dujiao_sieve(int n){//杜教筛
	if(n<=maxn) return sum_phi[n];
	if(ans_phi.count(n)) return ans_phi[n];
	ll res=(ll)n*(n+1)/2;
	for(int l=2,r;l<=n;l=r+1){
		r=n/(n/l);
		res=(res-(ll)(r-l+1)*dujiao_sieve(n/l)%mod+mod)%mod;
	}
	ans_phi[n]=res;
	return res;
}
ll calc(int n,int m){//记忆化搜索
	if(m==0) return 0;
	if(n==1) return dujiao_sieve(m);
	if(ans[n].count(m)) return ans[n][m];
	ll res=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			res=(res+(ll)phi[n/i]*calc(i,m/i)%mod)%mod;
			if(i!=n/i) res=(res+(ll)phi[i]*calc(n/i,m/(n/i))%mod)%mod;
		}
	}
	ans[n][m]=res;
	return res;
}

int n,m;
int main(){
	sieve(maxn);
	scanf("%d %d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+(ll)(i/low[i])*calc(low[i],m)%mod)%mod;
	}
	printf("%lld\n",ans);
}

 ```

