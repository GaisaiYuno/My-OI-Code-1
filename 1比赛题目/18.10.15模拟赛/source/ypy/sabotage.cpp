#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 1e14
using namespace std;
inline long long qread(){
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
int n;
long long a[maxn];
long long sum[maxn];
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
		sum[i]=sum[i-1]+a[i];
	}
	double ans=INF;
	double tmp=INF;
	for(int len=1;len<n-1;len++){
		tmp=INF;
		for(int i=2;i<n;i++){
			if(i+len-1>=n) continue;
			tmp=min(tmp,(double)(sum[n]-sum[i+len-1]+sum[i-1])/(double)(n-len));
		}
		ans=min(ans,tmp);
//		printf("f(%d)=%.3f\n",len,tmp);
//		printf("%.3f\n",tmp);
	}
	printf("%.3f",ans);
}
