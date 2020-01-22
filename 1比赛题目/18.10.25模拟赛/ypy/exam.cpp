#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
#define maxn 100005
#define maxm 100005
#define INF 0x7fffffffffffffff
using namespace std;
long long A,B,C;
int n,m;
long long maxb;
long long t[maxn];
long long b[maxm];
long long sumt[maxm];
long long sumb[maxm];
long long get_upval(long long *a,long long *s,int size,long long x){//查询a数组(前缀和为s数组）中大于x的数的超过部分之和 即sum(a[i]-x) a[i]>x 
	int l=upper_bound(a+1,a+1+size,x)-a;
	return s[size]-s[l-1]-x*(size-l+1);
}
long long get_downval(long long *a,long long *s,int size,long long x){//查询a数组(前缀和为s数组）中小于x的数的超过部分之和 即sum(x-a[i]) a[i]<x 
	int l=lower_bound(a+1,a+1+size,x)-a;
	return x*(l-1)-s[l-1];
}

long long solve(){
	long long sum_tch=0,sum_over=0,sum_less=0;
	long long ans=INF;
	long long maxv,minv;
	minv=b[1];
	maxv=b[m];
	for(int i=minv;i<=maxv;i++){
		sum_tch=get_upval(b,sumb,m,i);
		sum_less=get_downval(b,sumb,m,i);
		sum_over=get_downval(t,sumt,n,i);
		if(A>B){
			if(sum_tch*B+sum_over*C<0)continue;
			ans=min(ans,sum_tch*B+sum_over*C);
		}else{
			if(sum_tch<=sum_less){
				if(sum_tch*A+sum_over*C<0) continue;
				ans=min(ans,sum_tch*A+sum_over*C);
			}
			else {
				if(sum_less*A+(sum_tch-sum_less)*B+sum_over*C<0) continue;//防止爆long long造成的负数 
				ans=min(ans,sum_less*A+(sum_tch-sum_less)*B+sum_over*C);
			}
		}
	}
	return ans;
}
int main(){
	scanf("%lld %lld %lld",&A,&B,&C);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	} 
	sort(t+1,t+1+n);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		sumt[i]=sumt[i-1]+t[i];
	}
	for(int i=1;i<=m;i++){
		sumb[i]=sumb[i-1]+b[i];
	} 
	maxb=b[m];
	long long ans=0;
	ans=solve();
	printf("%lld\n",ans);
} 
//For my love Selina
