## [BZOJ 3509] [CodeChef\] COUNTARI (FFT+分块)

### 题面

给出一个长度为n的数组,问有多少三元组$(i,j,k)$满足$i<j<k,a_j-a_i=a_k-a_j$

$n \leq 10^5, a_i \leq 30000$

### 分析

记$m=\max(a_i)$

先做一点变形$a_i+a_k=2a_j$.那么枚举j,把j左边的和右边的所有数字找出来,找出有哪些数字对的和为$2a_j$。

维护当前块左边每个数的出现次数cntl,，和右边块的出现次数cntr。

那么数字和为$2a_j$的方案数就是$\sum_{i=0}^{2a_j} cntl(i)cntr(2a_j-i)$

这是一个卷积的形式,可以FFT.令:

$A(x)=\sum_{i=0}^{m} cntl(i) x^i $

$B(x)=\sum_{i=0}^{m} cntr(i) x^i $

$A*B$的第$2a_j$项的系数就是答案.但是做n次FFT的复杂度是$O(n^2 \log n)$,显然是跑不过去的.

我们要平衡一下复杂度，容易想到分块。设块大小为T

#### i,j,k均不在同一个块的情况

我们枚举j在第几个块,从左到右扫描第2~n-1个块,每块把左边和右边FFT卷积。枚举块内的每个数x,和为$2x$的方案数就是卷积结果里第$2x$项的系数.

时间复杂度$O(\frac{n}{B} \times m \log m)$

#### i,j,k至少有2个在同一个块的情况

直接暴力从小到大在块内枚举$k,j(j<k)$.然后讨论j在k前还是在k后。同样维护2个数组cntl表示当前块前面的数的出现次数，cntr表示k后面的数的个数。

如果i在j前,那么答案就是$cntl[a_j*2-a_k]$

如果i在k后，那么答案就是$cntr[a_k*2-a_j]$

注意到cntl不包含当前块，而cntr包含当前块，这样$i,j,k$在同一个块的情况只会被算1次

时间复杂度$O(\frac{n}{B} \times B \times B)=O(nB)$

总时间复杂度$O(nB+\frac{n}{B}m\log m)$

根据基本不等式,$B$取$\sqrt{m \log m}$时最优.总时间复杂$O(n\sqrt{m \log m})$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200000
using namespace std;
typedef long double db;
typedef long long ll;
const db pi=acos(-1.0);
struct com{
    double real;
    double imag;
    com(){

    } 
    com(double _real,double _imag){
        real=_real;
        imag=_imag;
    }
    com(double x){
        real=x;
        imag=0;
    }
    void operator = (const com x){
        this->real=x.real;
        this->imag=x.imag;
    }
    void operator = (const double x){
        this->real=x;
        this->imag=0;
    }
    friend com operator + (com p,com q){
        return com(p.real+q.real,p.imag+q.imag);
    }
    friend com operator + (com p,double q){
        return com(p.real+q,p.imag);
    }
    void operator += (com q){
        *this=*this+q;
    }
    void operator += (double q){
        *this=*this+q;
    }
    friend com operator - (com p,com q){
        return com(p.real-q.real,p.imag-q.imag);
    }
    friend com operator - (com p,double q){
        return com(p.real-q,p.imag);
    }
    void operator -= (com q){
        *this=*this-q;
    }
    void operator -= (double q){
        *this=*this-q;
    }
    friend com operator * (com p,com q){
        return com(p.real*q.real-p.imag*q.imag,p.real*q.imag+p.imag*q.real);
    }
    friend com operator * (com p,double q){
        return com(p.real*q,p.imag*q);
    } 
    void operator *= (com q){
        *this=(*this)*q;
    }
    void operator *= (double q){
        *this=(*this)*q;
    }
    friend com operator / (com p,double q){
        return com(p.real/q,p.imag/q);
    } 
    void operator /= (double q){
        *this=(*this)/q;
    } 
    void print(){
        printf("%lf + %lf i ",real,imag);
    }
};
void fft(com *x,int n,int type){
	static int rev[maxn+5];
	int dn=1,k=0;
	while(dn<n){
		dn*=2;
		k++;
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),sin(2*pi/sz)*type);
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=1;
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk*=wn1;
			}
		}
	}
	if(type==-1) for(int i=0;i<n;i++) x[i]/=n;
}
void mul(com *a,com *b,com *ans,int n){
	fft(a,n,1);
	if(a!=b) fft(b,n,1);
	for(int i=0;i<n;i++) ans[i]=a[i]*b[i];
	fft(ans,n,-1);
}

int n;
int bsz,bcnt;
int a[maxn+5]; 
int bel[maxn+5];
int lb[maxn+5],rb[maxn+5];//预处理每个数的左右边界，卡常 
void ini_block(){
	bsz=sqrt(n*log(n)/log(2));
	bcnt=1;
	for(int i=1;i<=n;i++){
		bel[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	for(int i=1;i<=bcnt;i++){
		lb[i]=bsz*(i-1)+1;
		rb[i]=min(i*bsz,n); 
	}
} 

int cntl[maxn+5],cntr[maxn+5];
com fl[maxn+5],fr[maxn+5],res[maxn+5];
int main(){
	scanf("%d",&n);
	ini_block();
	int maxv=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxv=max(maxv,a[i]);
	} 
	//i,j,k有>=2个在同一块内，直接暴力O(n/B*B^2)=O(Bn)
	ll ans=0;
	for(int i=n;i>=1;i--) cntr[a[i]]++;
	for(int id=1;id<=bcnt;id++){
		//cntl记录的是当前块前面的数的出现情况
		//cntr记录的是i后面的数的出现情况
		//注意i,j,k均在一个块内的情况只能被算1次  
		for(int k=lb[id];k<=rb[id];k++){
			cntr[a[k]]--;
			for(int j=lb[id];j<k;j++){
				int ai=a[j]*2-a[k];
				if(ai>=0&&ai<=maxn) ans+=cntl[ai]; 
				ai=a[k]*2-a[j];
				if(ai>=0&&ai<=maxn) ans+=cntr[ai];//这样只有这个时候会算到i,j,k在同一个块里的情况 
			}
			
		}
		for(int j=lb[id];j<=rb[id];j++) cntl[a[j]]++;
	} 
	memset(cntl,0,sizeof(cntl));
	memset(cntr,0,sizeof(cntr));
	for(int i=n;i>=lb[2];i--) cntr[a[i]]++;
	for(int i=1;i<=rb[1];i++) cntl[a[i]]++; 
	for(int id=2;id<bcnt;id++){
		for(int j=lb[id];j<=rb[id];j++) cntr[a[j]]--;
		for(int j=0;j<=maxv;j++){
			fl[j]=cntl[j];
			fr[j]=cntr[j];
		}
		int dn=1;
		while(dn<=maxv*2) dn*=2;
		mul(fl,fr,res,dn);
		for(int j=lb[id];j<=rb[id];j++){
			ans+=(ll)(res[a[j]*2].real+0.5);
		}
		for(int j=0;j<=dn;j++){
			fl[j]=0;
			fr[j]=0;
			res[j]=0;
		}
		for(int j=lb[id];j<=rb[id];j++) cntl[a[j]]++;
	} 
	printf("%lld\n",ans);
}
```

