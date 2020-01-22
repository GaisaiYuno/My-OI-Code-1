//http://111.230.183.91:8080/problem/306
#include<iostream>
#include<cstdio>
#define maxn 200005
using namespace std;
int n,k,q;
long long d[maxn];
long long sum[maxn];
int main(){
	int l,r;
	scanf("%d %d %d",&n,&k,&q);
	int mv=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l,&r);
		d[l]++;
		d[r+1]--;
		mv=max(mv,r);
	}
	for(int i=1;i<=mv;i++){
		d[i]+=d[i-1];
	}
	for(int i=1;i<=mv;i++){
		if(d[i]>=k) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		printf("%lld\n",sum[min(r,mv)]-sum[l-1]);
	} 
}
