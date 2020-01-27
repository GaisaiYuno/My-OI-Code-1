## [BZOJ 3527] [ZJOI2014]力(FFT)

###　题面

求$ F_j=\sum_{i<j} \frac{q_i q_j}{(i-j)^2}-\sum_{i>j} \frac{q_i q_j}{(i-j)^2} $

题外话:这题叫”力“，大概是因为这个式子长得很像电荷间作用力的公式。

### 分析

设$E_i=\frac{F_i}{q_i}$(题外话:其实就是电场强度).

$$\begin{aligned}E_i &=\sum_{j<i} \frac{q_j}{(j-i)^2}-\sum_{j>i} \frac{q_j}{(j-i)^2} \\ E_i&=\sum_{j=1}^{i-1} \frac{q_j}{(j-i)^2} - \sum_{j=i+1}^{n} \frac{q_j}{(j-i)^2} \end{aligned}$$

令$f(i)=q_i, g(i)=\frac{1}{i^2}$

$$ E_i=\sum_{j=1}^{i-1} f(j)g(i-j) - \sum_{j=i+1}^{n} f(j)g(j-i) $$

 注意到第一个式子就是卷积的形式，但是第二个式子$j+(j−i)$不是一个常数，考虑变换形式。

令$g'(i)=g(n-i)$,那么$g(j-i)=g'(n-j+i)$

于是式子化成: 

$$ E_i=\sum_{j=1}^{i-1} f(j)g(i-j) - \sum_{j=i+1}^{n} f(j)g'(n-j+i) $$

$j+(n-j+i)=n-i$,为一常数，就可以直接卷积了

 但是，做两次FFT有一点麻烦，考虑将g数组开两倍，同时包含$g,g’$，因为n+i>n,把g'放在n以后的部分。即

$$g(i)=\begin{cases} -\frac{1}{(n-i)^2},i \in[1,n] \\ -\frac{1}{(i-n)^2},i \in[n+1,2n]\end{cases}$$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
#define maxn 500000
using namespace std;
typedef complex<double> com;
const double pi=acos(-1.0);
int rev[maxn+5];
com a[maxn+5],b[maxn+5],c[maxn+5];
void fft(com *x,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	}	
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=com(1,0);
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk*=wn1;
			}
		}
	}
} 

int n;
int main(){
	double x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&x);
		a[i]=x;
	}
	for(int i=0;i<n;i++) b[i]=-1.0/(1.0*(n-i)*(n-i));
	for(int i=n+1;i<=n*2;i++) b[i]=1.0/(1.0*(i-n)*(i-n));
	
	int k=0,m=1;
	while(m<=n*2){
		m*=2;
		k++;
	}
	for(int i=0;i<m;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	
	fft(a,m,1);
	fft(b,m,1);
	for(int i=0;i<m;i++) c[i]=a[i]*b[i];
	fft(c,m,-1);
	for(int i=n;i<=n*2-1;i++) printf("%.3f\n",c[i].real()/m);
}
```







