 
//设区间为[i,j] 
//ans=(sum[n]-sum[j]+sum[i-1])/(n-j+i-1)
//二分ans，设当前二分值为k
//则需判断 sum[n]-sum[j]+sum[i-1]和kn-kj+k(i-1) 的关系 
//若 sum[n]-sum[j]+sum[i-1]>=kn-kj+k(i-1)
//    sum[n]-kn-(sum[j]-kj)+(sum[i-1]-(i-1))>=0
//令f[x]=sum[x]-k*x
// 则f[n]>=f[j]-f[i-1]
//显然不能暴力枚举每一个i,j,用贪心的方法，选最大的f[j],最小的f[i-1], f[j]-f[i-1]取最大值
//直接判断 f[n]和 max(f[j]-f[i-1]) 的关系即可
//若f[n]>=max(f[j]-f[i-1]),则k可以更大，否则k会更小 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define eps 1e-5
using namespace std;
inline int qread(){
	int x=0,sign=1;
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
int n;
int a[maxn];
double sum[maxn];
double f[maxn];
double minf[maxn],maxf[maxn];//minf[i]维护[1,i]最小f，maxf[i]维护[i,n-1]最大f （注意最后一个不能选，所以j最大只能到n-1,i最小为2） 
int check(double k){
	for(int i=1;i<=n;i++) f[i]=sum[i]-i*k;
	minf[1]=f[1];
	for(int i=2;i<=n;i++){
		minf[i]=min(minf[i-1],f[i]);
	}
	maxf[n-1]=f[n-1];
	for(int i=n-2;i>=1;i--){
		maxf[i]=max(maxf[i+1],f[i]);
	}
	for(int i=2;i<=n-1;i++){
		if(f[n]<maxf[i]-minf[i-1]) return 0;
	}
	return 1;
}

double bin_search(){
	double l=1,r=sum[n]/(n-1);
	double mid;
	while(fabs(r-l)>eps){
		mid=(l+r)/2;
		if(check(mid)) l=mid+eps;
		else r=mid-eps;
	}
	return mid;
}

int main(){
//	freopen("testdata.in","r",stdin);
	n=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	printf("%.3f",bin_search()); 
}
