## [Codeforces 364D]Ghd(随机算法)

### 题面

给出n个正整数，在其中选出n/2(向上取整)个数，要求这些数的最大公约数最大，求最大公约数的最大值

### 分析

每个数被选到的概率$\geq \frac{1}{2}$，因此我们随机选t个数x，对于每个数处理出它所能得到的最大答案。显然最大公约数一定是x的一个因数。

先对x进行因数分解。并求出x与所有a[i]的gcd ,看看哪个因数成为x和a[i]的gcd的次数最多，且次数超过n/2 。具体做法是,对于每个因数d[u],记录满足gcd(x,a[i])=d[u]的i的个数cnt[u]。然后对于两个因数d[i],d[j] (d[i]<d[j]),如果d[i]能整除d[j]，说明j对应的数字也可以被这个的整除，应当把cnt[j]加到cnt[i]上 。最后扫描cnt数组，如果cnt[i]*2>n,就更新答案

这样的时间复杂度是$O(k(n\log max(a_i)+\sqrt{max(a_i)}+max(d_{a_i}^2) \ )$,其中$d_{a_i}$为$a_i$的因数个数。

我们取k个数，这k个数不在最终答案的集合的概率为$1-2^{-k}$,经过实验，取k=10的时候能较好的平衡时间复杂度和正确概率。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
#define maxn 1000000
#define maxt 10 //随机选数次数 
using namespace std;
typedef long long ll; 
int n;
ll  a[maxn+5];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int random(int l,int r){
	return (long long )rand()*rand()%(r-l+1)+l;
} 

int sz=0;
ll d[maxn+5];
int cnt[maxn+5];
void divide(ll x){
	sz=0;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			d[++sz]=i;
			if(x/i!=i) d[++sz]=x/i; 
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]); 
	ll ans=0;
	for(int cas=1;cas<=maxt;cas++){
/*
		每个数有1/2的概率被选中，随机t个数，假设它被选中，求出选中它时的答案 
		对随机出的数x分解因数，并求出x与所有a[i]的gcd 
		看看哪个因数成为x和a[i]的gcd的次数最多，且次数超过n/2 
		对于求出来的公因数，我们去从大到小找一个会成为超过一半数的因数的数字。
		具体做法是，选择一个因数，去找比它大的因数，
		如果它能整除大因数，说明大因数对应的数字也可以被这个小因数整除，应当把加到这个小因数的计数上 
		时间复杂度O(n+d^2)
		但d很小，所以不会TLE 
*/
		ll x=a[random(1,n)];
		divide(x);
		sort(d+1,d+sz+1);
		for(int i=1;i<=sz;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			int pos=lower_bound(d+1,d+1+sz,gcd(a[i],x))-d;
			cnt[pos]++;
		}
		for(int i=1;i<=sz;i++){
			for(int j=i+1;j<=sz;j++){
				if(d[j]%d[i]==0) cnt[i]+=cnt[j];
			}
		}
		for(int i=sz;i>=1;i--){
			if(cnt[i]*2>=n){
				ans=max(ans,d[i]);
//				break;
			}
		}
	}
	printf("%I64d\n",ans);
}
/*
2
11111111111
11111111111
*/ 

```



