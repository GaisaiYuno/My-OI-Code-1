## [Codeforces 163D]Large Refrigerator (DFS+剪枝)

### 题面

已知一个长方体的体积为V，三边长a,b,c均为正整数，求长方体的最小表面积S

V以质因数分解的形式给出

### 分析

暴力做法很容易想到，按照质因子的指数枚举a,b，然后就能直接算出c,然后就可以得到表面积S=2(ab+bc+ac)

考虑优化：

1.搜索顺序：保证$a \geq b \geq c$,枚举质因数时从大到小枚举a,从小到大枚举b

2.可行性剪枝:枚举a的时候保证$a^3 \leq V$,枚举b时保证$ab^2 \leq V$

3.最优化剪枝:发现$S=2(ab+bc+ac)=2a(b+c)+2bc$,又因为$bc=\frac{V}{a}$,$S=2a(b+c)+\frac{2V}{a}$。根据基本不等式有$b+c \geq 2 \sqrt{bc}=2\sqrt{\frac{V}{a}}$.所以枚举a的时候判断若$\frac{2V}{a}+4a\sqrt{\frac{V}{a}}$比当前答案大，就不要再继续搜索b了

4.常数优化：快读快写，预处理质因数的i次方

5.易错点：a,b,c的乘积可能会爆long long,要转成double再判断



### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
#define rg register
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}
inline void qread(ll &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
 
int t,n;
ll V;
ll p[maxn+5];
ll k[maxn+5];
ll mpow[maxn+5][maxn+5];
ll ans=INF;
ll ansa,ansb,ansc;
ll maxa;
void dfsb(int deep,ll va,ll vb){
	if((double)va*vb*vb>V) return;
	if(deep>n){
		ll vc=V/va/vb;
		if(2*(va*vb+va*vc+vb*vc)<ans){
			ans=2*(va*vb+va*vc+vb*vc);
			ansa=va;
			ansb=vb;
			ansc=vc;
		}
		return;
	}
	for(rg int i=0;i<=k[deep];i++){
		k[deep]-=i;
		dfsb(deep+1,va,vb*mpow[deep][i]);
		k[deep]+=i;
	}
}
void dfsa(int deep,ll va){
	if((double)va*va*va>V) return;
	if(deep>n){
		double mins=2.0*V/va+4.0*va*sqrt(1.0*V/va);
		if(mins>1.0*ans) return; //最优化剪枝 
		//S=2(ab+bc+ac)=2a(b+c)+2V/a
		//由基本不等式得b+c>=2sqrt(bc)
		//S>=2a*2sqrt(V/a)+2V/a
		dfsb(1,va,1); 
		return;
	} 
	for(rg int i=k[deep];i>=0;i--){
		k[deep]-=i;
		dfsa(deep+1,va*mpow[deep][i]);
		k[deep]+=i;
	}
}
 
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	qread(t);
	while(t--){
		qread(n);
		V=1;
		for(int i=1;i<=n;i++){
			qread(p[i]);
			qread(k[i]);
//			V*=fast_pow(p[i],k[i]);
		}
		for(int i=1;i<=n;i++){
			mpow[i][0]=1;
			for(int j=1;j<=k[i];j++){
				mpow[i][j]=mpow[i][j-1]*p[i];
			}
			V*=mpow[i][k[i]];
		}
		ans=INF;
		dfsa(1,1);
		qprint(ans);
		putchar(' '); 
		qprint(ansa);
		putchar(' '); 
		qprint(ansb);
		putchar(' '); 
		qprint(ansc);
		putchar('\n'); 
	}
} 
```





