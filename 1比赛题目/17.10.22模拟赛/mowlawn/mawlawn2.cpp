//洛谷 修剪草坪 O(n*k)
#include<iostream>
#include<cstdio>
#define maxn 100005
long long e[maxn],f[maxn];
long long n,k,total;
using namespace std;
inline long long read(){//输入输出优化 
	long long x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main(){
	freopen("mowlawn.9.in","r",stdin);
	n=read();k=read();
	for(register int i=1;i<=n;i++){//register可以加速？ 
		e[i]=read();
		total+=e[i];
	}
	long long tmp;
	for(register int i=k+1;i<=n;i++){
		tmp=0xfffffffffffffff;
		for(register int j=i-k;j<=i;j++){
			if(tmp>f[j-1]+e[j]) tmp=f[j-1]+e[j];
			//tmp=min(tmp,f[j-1]+e[j]);
		}
		f[i]=tmp;
	}
	printf("%lld",total-f[n]);
}
/*
状态转移方程(1) 
    f[i]=min{f[j-1]+i~j效率之和,f[i]}   j∈[i-k,i]
状态转移方程(2) 
  先求出总效率 
  再求i只牛最小效率,不超过k只连续 
  f[i]=min{f[j-1]+e[j],f[i]}   j∈[i-k,i] 
  用总效率减去最小效率就能得到最大效率，比直接求最大效率快 
*/ 
