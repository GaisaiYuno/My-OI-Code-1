## [BZOJ 3771] Triple(FFT+生成函数)

### 题面

 给出 n个物品，价值为别为$w_i$且各不相同，现在可以取1个、2个或3个，问每种价值和有几种情况？ 

### 分析

这种计数问题容易想到生成函数。

设生成函数$A(x)=\sum_{i=1}^{n} x^{w_i}$，指数为价值，系数为选的方案数。A表示每种物品取1个的方案数。同理，我们可以写出每种物品取2个和3个的生成函数。

$B(x)=\sum_{i=1}^{n} x^{2w_i}$

$C(x)=\sum_{i=1}^{n} x^{3w_i}$

然后就开始大力容斥.

#### 取3个不同物品的情况

直接取3个物品的方案数为$A^3(x)$，但是我们还需要减去重复的,如$(a,a,b),(a,b,a)$就算同一种情况。选2个物品$a$的方案为$B(x)$，再选一个物品$b$的方案为$A(x)$,任意排列有3种。因此要减$3A(x)B(x)$

然而每种物品取3个$(a,a,a)$这样的方案会被减去3次，而实际上只需要减去1次，所以还要加回$2C(x)$

注意到$(a,b,c)$的6种不同排列方案只算一次。总答案为

$$\frac{A^3(x)-3A(x)B(x)+2C(x)}{6}$$

#### 取2个不同物品的情况

直接取3个物品的方案为$A^2(x)$。重复的$(a,a)$这种情况的方案为$B(x)$,并且$(a,b)$的2种排列只算1次。总答案为

$$\frac{A^2(x)-B(x))}{2}$$

#### 取1个不同物品的方案

很简单，就是$A(x)$



综上，总答案为

$$\frac{A^3(x)-3A(x)B(x)+2C(x)}{6}+\frac{A^2(x)-B(x))}{2}+A(x)$$

先把A,B,C用FFT转成点值表达式然后相乘，再逆变换一下就得到答案.

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 400000
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
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
	friend com operator - (com p,com q){
		return com(p.real-q.real,p.imag-q.imag);
	}
	friend com operator - (com p,double q){
		return com(p.real-q,p.imag);
	}
	friend com operator * (com p,com q){
		return com(p.real*q.real-p.imag*q.imag,p.real*q.imag+p.imag*q.real);
	}
	friend com operator * (com p,double q){
		return com(p.real*q,p.imag*q);
	} 
	friend com operator / (com p,double q){
		return com(p.real/q,p.imag/q);
	} 
	void print(){
		printf("%lf + %lf i ",real,imag);
	}
};
void fft(com *x,int n,int type){
	static int rev[maxn+5];
	int tn=1,k=0;
	while(tn<n){
		k++;
		tn*=2;
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=1;
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk=wnk*wn1;
			}
		}
	}
	if(type==-1){
		for(int i=0;i<n;i++) x[i].real/=n;
	}
} 
void mul(com *a,com *b,com *ans,int n){
//	fft(a,n,1);
//	fft(b,n,1);
//避免多次fft 
	for(int i=0;i<n;i++) ans[i]=a[i]*b[i];
	fft(ans,n,-1); 
}

int n;
int val[maxn+5];
com a[maxn+5],b[maxn+5],c[maxn+5];
com ans[maxn+5];
int main(){
	scanf("%d",&n);
	int mv=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		a[val[i]]=a[val[i]]+1;	
		b[val[i]*2]=b[val[i]*2]+1;	
		c[val[i]*3]=c[val[i]*3]+1;
		mv=max(mv,val[i]);	
	} 
	int tn=1,k=0;
	while(tn<mv*3){
		k++;
		tn*=2;
	}
	fft(a,tn,1);
	fft(b,tn,1);
	fft(c,tn,1);
	for(int i=0;i<tn;i++){
		ans[i]=(a[i]*a[i]*a[i]-3*a[i]*b[i]+2*c[i])/6+(a[i]*a[i]-b[i])/2+a[i];
	}
	fft(ans,tn,-1);
	for(int i=0;i<=mv*3;i++){
		if(ll(ans[i].real+0.5)){
			printf("%d %lld\n",i,ll(ans[i].real+0.5));
		}
	}
}
```

