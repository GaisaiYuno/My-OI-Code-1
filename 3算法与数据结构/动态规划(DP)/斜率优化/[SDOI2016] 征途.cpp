#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3000
using namespace std;
typedef long long ll;
int n,m;
int a[maxn+5];
ll s[maxn+5];
ll dp[maxn+5][maxn+5];
int head,tail;
int q[maxn+5];
double get_up(int x,int j1,int j2){
	return (dp[x-1][j2]+s[j2]*s[j2])-(dp[x-1][j1]+s[j1]*s[j1]);
}
double get_down(int x,int j1,int j2){
	return s[j2]-s[j1];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int x=1;x<=m;x++){
		head=1,tail=1;
		q[head]=0;
		for(int i=1;i<=n;i++){
			while(head<tail&&get_up(x,q[head],q[head+1])/get_down(x,q[head],q[head+1])<=2*s[i]) head++;
			int j=q[head];
			dp[x][i]=dp[x-1][j]+(s[i]-s[j])*(s[i]-s[j]);
			while(head<tail&&get_up(x,q[tail-1],q[tail])/get_down(x,q[tail-1],q[tail])>=get_up(x,q[tail],i)/get_down(x,q[tail],i)) tail--;
			q[++tail]=i;
		}
	}
	printf("%lld\n",m*dp[m][n]-s[n]*s[n]);
} 
