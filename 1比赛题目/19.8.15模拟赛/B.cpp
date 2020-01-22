#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxk 200
using namespace std;
typedef long long ll;
inline void qread(int& x){
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
int n,K;
int a[maxn+5];
ll dp[maxk+5][maxn+5];
ll sum[maxn+5]; 
int q[maxn+5];
inline double get_up(int x,int j1,int j2){
	return dp[x-1][j1]-dp[x-1][j2];
}
inline double get_down(int x,int j1,int j2){
	return (sum[j2]-sum[j1]);
}
int main(){
	qread(n);
	qread(K);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int x=1;x<=K;x++){
		int head=1,tail=1;
		q[head]=0;
		for(int i=1;i<=n;i++){
			while(head<tail&&get_up(x,q[head],q[head+1])<=(sum[i]-sum[n])*get_down(x,q[head],q[head+1]) )head++;
			int j=q[head];
			dp[x][i]=dp[x-1][j]+(sum[i]-sum[j])*(sum[n]-sum[i]);
			while(head<tail&&get_up(x,q[tail],q[tail-1])*get_down(x,i,q[tail])>=get_up(x,i,q[tail])*get_down(x,q[tail],q[tail-1])) tail--;
			q[++tail]=i;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[K][i]); 
	printf("%lld\n",ans);
}
