#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define mod 1000000007
using namespace std;
int n,k;
int id[maxn+5];
int t[maxn+5];
int main(){
#ifndef LOCAL
	freopen("shit.in","r",stdin);
	freopen("shit.out","w",stdout);
#endif
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		id[i]=i;
		scanf("%d",&t[i]);
	}
	sort(t+1,t+1+n);
	long long sum=0;
	long long tim=0;
	for(int i=1;i<=n;i++){
		tim+=t[i];
		tim%=mod;
		sum+=tim;
		sum%=mod;
	}
	long long fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
		fact%=mod;
	}
	sum=sum*fact%mod;
	printf("%lld\n",sum);
}
