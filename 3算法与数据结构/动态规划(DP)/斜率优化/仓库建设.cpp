//http://119.29.55.79/contest/77/problem/1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000 
using namespace std;
typedef long long ll;
int n;
int x[maxn+5];
int c[maxn+5];
int p[maxn+5];
ll sump[maxn+5],sumxp[maxn+5];
ll dp[maxn+5];
int head,tail;
int q[maxn+5];
inline ll get_up(int j1,int j2){
	return (dp[j2]-sumxp[j2])-(dp[j1]-sumxp[j1]);
}
inline ll get_down(int j1,int j2){
	return sump[j2]-sump[j1];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&x[i],&p[i],&c[i]);
	for(int i=1;i<=n;i++){
		sump[i]=sump[i-1]+p[i];
		sumxp[i]=sumxp[i-1]-((ll)p[i]*x[i]);
	}
	dp[0]=0;
	head=1,tail=1;
	q[head]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&get_up(q[head],q[head+1])<=x[i]*get_down(q[head],q[head+1])) head++;
//		printf("best=%d ",q[head]);
		dp[i]=dp[q[head]]+c[i]+x[i]*(sump[i-1]-sump[q[head]])+sumxp[i-1]-sumxp[q[head]];
		while(head<tail&&get_up(q[tail-1],q[tail])*get_down(q[tail],i)>=get_up(q[tail],i)*get_down(q[tail-1],q[tail])) tail--;
		q[++tail]=i;
//		printf("%lld\n",dp[i]);
	}
	printf("%lld\n",dp[n]);	
}
