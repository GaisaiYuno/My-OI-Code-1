//https://www.luogu.org/problemnew/show/P3195 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50000
using namespace std;
int n,l;
int c[maxn+5];
long long s[maxn+5];
long long dp[maxn+5]; 

int head,tail;
int q[maxn+5];
 
inline long long get_up(int j,int k){
	return (dp[j]+(s[j]+j)*(s[j]+j))-(dp[k]+(s[k]+k)*(s[k]+k)); 
}
inline long long get_down(int j,int k){
	return (s[j]+j)-(s[k]+k);
}

int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		s[i]=s[i-1]+c[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	head=tail=1;
	q[head]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&get_up(q[head+1],q[head])<=2*(s[i]+i-1-l)*get_down(q[head+1],q[head])) head++;
		dp[i]=dp[q[head]]+(s[i]-s[q[head]]+i-q[head]-1-l)*(s[i]-s[q[head]]+i-q[head]-1-l);
		while(head<tail&&get_up(q[tail],q[tail-1])*get_down(i,q[tail])>=get_up(i,q[tail])*get_down(q[tail],q[tail-1])) tail--;
		q[++tail]=i;
	}
	printf("%lld\n",dp[n]);	
}

