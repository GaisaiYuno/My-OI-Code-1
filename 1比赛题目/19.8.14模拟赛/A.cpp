#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
ll dp[maxn+5]; 
int q[maxn+5];
int head,tail;
inline double get_up(int j,int k){
	return (dp[k]+k/2.0+(ll)k*k/2.0)-(dp[j]+j/2.0+(ll)j*j/2.0);
}
inline double get_down(int j,int k){
	return (k-j);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0]=0;
	head=tail=1;
	q[head]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&get_up(q[head],q[head+1])/get_down(q[head],q[head+1])<i) head++;
		int j=q[head];
		dp[i]=dp[j]+a[i]+(ll)(i-j)*(i-j-1)/2;
//		printf("%d %lld\n",j,dp[i]);
		while(head<tail&&get_up(q[tail-1],q[tail])/get_down(q[tail-1],q[tail])>get_up(q[tail],i)/get_down(q[tail],i)) tail--;
		q[++tail]=i;

	}
	printf("%lld\n",dp[n]);
}
 
