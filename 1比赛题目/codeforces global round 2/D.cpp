#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
long long s[maxn];
long long d[maxn];
struct node{
	long long dif;
	int id;
	friend  bool operator < (node p,node q){
		return p.dif<q.dif;
	}
}a[maxn];
long long sumd[maxn];
int bin_search(int l,int r,long long k){
	int mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid].dif<=k){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans+1;
}
long long solve(long long l,long long r){
	int pos=bin_search(1,n-1,r-l);
	long long ans=0;
	if(pos-1>0) ans+=sumd[pos-1];
	if(pos<n){
		ans+=(n-pos)*(r-l+1);
	}
	ans+=(r-l+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&s[i]);
	sort(s+1,s+1+n);
	for(int i=1;i<n;i++){
		d[i]=s[i+1]-s[i];
	}
	for(int i=1;i<n;i++){
		a[i].dif=d[i];
		a[i].id=i;
	}
	sort(a+1,a+n);
	for(int i=1;i<n;i++){
		sumd[i]=sumd[i-1]+a[i].dif;
	}
	long long l,r;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%I64d %I64d",&l,&r);
		printf("%I64d\n",solve(l,r));
	}
}

