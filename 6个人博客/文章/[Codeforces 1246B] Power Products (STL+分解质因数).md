### [Codeforces 1246B] Power Products (STL+分解质因数)

###　题面

给出一个长度为$n$的序列$a_i$和常数k,求有多少个数对$(i,j)$满足$a_i \times a_j = x^k (x \in \mathbb{N}^+)$。即这两个数乘起来恰好为一个正整数的$k$次方

$a_i,n \leq 10^5$

### 分析

考虑$x^k$的质因数分解式  , 那么每一项的指数一定是k的倍数，即 $k|x_i$. 

因此对于每个 $a_i$, 把它的质因数分解结果$\sum p_i^{x_i}$记录在一个数组中，每个元素形如$(p_i, x_i \ \mathrm{mod}\ k )$

那么 $a_j$的质因数分解为 $\sum p_i^{k-x_i \ \mathrm{mod} k } $. 所以只要求有多少个数组满足每一项都是$ (p_i,k-x_i \mathrm{mod}\ k) $. ```map< vector< pair<int,int> >, int> cnt;  ``` 

 每个数组的大小为 $O(\log n)$ ,总时间复杂度为 $O(n \log ^2 n)$

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map> 
#include<vector> 
#define maxv 100000
#define maxn 100000 
using namespace std;
typedef long long ll;
int n,k;
map< vector< pair<int,int> >, int> cnt; 
vector< pair<int,int> >p1,p2;
int a[maxn+5];
int vis[maxv+5];
int minprime[maxv+5];
int prime[maxv+5];
 
 
void sieve(int n) {
	vis[1]=1;
	for(int i=2; i<=n; i++) {
		if(!vis[i]) {
			minprime[i]=i;
			prime[++k]=i;
		}
		for(ll j=1; j<=k&&(ll)i*prime[j]<=n; j++) {
			minprime[(ll)i*prime[j]]=prime[j];
			vis[(ll)i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
}
 
void divide(int x) {
	if(!vis[x]) {
		p1.push_back(make_pair(x,1));
		p2.push_back(make_pair(x,k-1)); 
		return;
	}
	while(x>1) {
		int t=minprime[x],u=0;;
		while(x%t==0&&x!=1) {
			x/=t;
			u=(u+1)%k;
		}
		if(u!=0){ 
			p1.push_back(make_pair(t,u));
			p2.push_back(make_pair(t,k-u));
		} 
	}
}
 
void print(vector< pair<int,int> > &x){
	for(int i=0;i<x.size();i++){
		printf("(%d,%d) ",x[i].first,x[i].second);
	}
	printf("\n");
}
int main(){
	sieve(100000);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		p1.clear();
		p2.clear();
		divide(a[i]);
//		print(p1);
//		print(p2);
		ans+=cnt[p2];
		cnt[p1]++;
		
	}
	printf("%I64d\n",ans);
}
```

