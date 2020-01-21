## [BZOJ 4332] [JSOI2012]分零食(DP+FFT)

###　题面

同学们依次排成了一列，其中有A位小朋友，有三个共同的欢乐系数O，S和U。如果有一位小朋友得到了x个糖果，那么她的欢乐程度就是$f(x)=Ox^2+Sx+U$
现在校长开始分糖果了，一共有M个糖果。有些小朋友可能得不到糖果，**对于那些得不到糖果的小朋友来说，欢乐程度就是1**。如果一位小朋友得不到糖果，那么在她身后的小朋友们也都得不到糖果。（即这一列得不到糖果的小朋友一定是最后的连续若干位）
所有分糖果的方案都是等概率的。现在问题是：期望情况下，所有小朋友的欢乐程度的乘积是多少？呆呆同学很快就有了一个思路，只要知道总的方案个数T和所有方案下欢乐程度乘积的总和S，就可以得到答案Ans=S/T。现在他已经求出来了T的答案，但是S怎么求呢？他就不知道了。你能告诉他么？
因为答案很大，你只需要告诉他S对P取模后的结果。



### 分析

~~题面osu好评~~

设$dp[i][j]$表示i个人里分j个零食得到的答案

那么$$dp[i][j]=\sum_{k=0}^{j} dp[i-1][j-k] f(j)$$

暴力递推是$O(nm^2)$的，我们发现后面的式子是一个卷积的形式，即$dp_i=dp_{i-1}*f$

由于卷积满足结合律，$dp_i=dp_0 * f^i=1*f^i=f^i$.但是我们要求的是$\sum_{i=1}^n dp[n][m]$,单点求值用FFT可以做到$O(m \log m \log n)$,求和的复杂度是$O(nm \log m \log n)$.因此，我们考虑快速幂分治的思想，想办法把问题范围缩小一半。

令$s_n=\sum_{i=1}^n dp_i$

则$$s_n=s_{\frac{n}{2}}+\sum_{i=\frac{n}{2}+1}^n dp_i=s_{\frac{n}{2}}+\sum_{i=\frac{n}{2}+1}^n f^i=s_{\frac{n}{2}}+\sum_{i=1}^{n/2} f^{i+n/2}$$

$$=s_{\frac{n}{2}}+f^{\frac{n}{2}}*\sum_{i=1}^{\frac{n}{2}} f^{i}$$

注意到$f^{\frac{n}{2}}=dp_{\frac{n}{2}},\sum_{i=1}^{n/2} f^{i}=s_{\frac{n}{2}}$那么

$$s_n=s_{\frac{n}{2}}+dp_{\frac{n}{2}}*s_{\frac{n}{2}}$$

类似快速幂倍增一下即可，答案就是$s[n][m]$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<complex>
#define maxn 300000
#include<cmath> 
using namespace std;
typedef complex<double> com;
typedef long long ll;
const double pi=acos(-1.0);

int n,m;
ll O,S,U;
ll mod;
void fft(com *x,int *rev,int n,int type){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=com(1,0);
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-tmp*wnk;
				x[i]=x[i]+tmp*wnk;
				wnk*=wn1;
			} 
		}
	} 
} 

struct poly{
	int len;
	ll arr[maxn+5];
	inline int size(){
		return len;
	}
	inline ll & operator [](int i){
		return arr[i];
	}
	friend void operator += (poly &p,poly &q){
		for(int i=0;i<=p.len;i++){
			p.arr[i]=(p.arr[i]+q.arr[i])%mod;
		}
	}
	void print(){
		for(int i=0;i<=len;i++) printf("%d ",arr[i]);
		printf("\n"); 
	} 
};
int rev[maxn+5]; 
 com tmpa[maxn+5],tmpb[maxn+5],tmpc[maxn+5];
void mul(poly &a,poly &b,poly &c){

	int tn=1,k=0;
	while(tn<=a.len*2){
		k++;
		tn*=2; 
	}
	for(int i=0;i<tn;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
		tmpa[i]=tmpb[i]=tmpc[i]=0;
	}
	for(int i=0;i<=a.len;i++){
		tmpa[i]=a[i];
		tmpb[i]=b[i];
	}
	fft(tmpa,rev,tn,1);
	fft(tmpb,rev,tn,1);
	for(int i=0;i<tn;i++) tmpc[i]=tmpa[i]*tmpb[i];
	fft(tmpc,rev,tn,-1);
	for(int i=0;i<=a.len;i++) c[i]=(ll)(tmpc[i].real()/tn+0.5)%mod;
}

poly f,g,tmp,a;
inline void fast_pow(int k){
	if(k==1){
		f.len=g.len=m;
		tmp.len=m;
		for(int i=0;i<=m;i++) f[i]=g[i]=a[i];
		return;
	}
	fast_pow(k>>1);
//	f.print();
//	g.print();
	mul(f,g,tmp);
//	tmp.print();
	f+=tmp;
	mul(g,g,g);
	if(k&1){
		mul(g,a,g);
		f+=g;
	}
} 


inline ll calc(ll x){
	return O*x*x%mod+S*x%mod+U%mod;
}
int main(){
	scanf("%d %lld",&m,&mod);
	scanf("%d %lld %lld %lld",&n,&O,&S,&U);
	for(int i=1;i<=m;i++) a[i]=calc(i)%mod; 
	//注意a[0]=0,而不是calc(0)，因为分到0的快乐度是1，对答案无影响，不用累加 
	fast_pow(n);
	printf("%lld\n",f[m]);
}

```



