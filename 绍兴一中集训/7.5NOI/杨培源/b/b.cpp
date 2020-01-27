// 正解是meet in the middle+斜率优化？ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50
using namespace std;
int a[maxn+5],b[maxn+5];
int n,mid,delta;
namespace brute_force {
	int p[maxn+5];
	int c[maxn+5];
	long long calc() {
		long long E=0,S=0;
		for(int i=1; i<=mid; i++) {
			E+=a[i];
			S+=E*b[i];
		}
		E+=delta;
		for(int i=mid+1; i<=n; i++) {
			E+=a[i];
			S+=E*b[i];
		}
		return S;
	}

	void solve() {
		for(int i=1; i<=n; i++) p[i]=i;
		long long ans=0;
		do {
			for(int i=1; i<=n; i++) c[i]=a[p[i]];
			ans=max(ans,calc());
		} while(next_permutation(b+1,b+1+n));
		printf("%lld\n",ans);
	}
}

namespace b_all_1{
	int cmp(int x,int y){
		return x>y;
	}
	void solve(){
		sort(a+1,a+1+n,cmp);
		long long E=0,S=0;
		for(int i=1; i<=mid; i++) {
			E+=a[i];
			S+=E;
		}
		E+=delta;
		for(int i=mid+1; i<=n; i++) {
			E+=a[i];
			S+=E;
		}
		printf("%lld\n",S);
	}
}

namespace a_all_1{
	int cmp(int x,int y){
		return x>y;
	}
	void solve(){
		sort(b+1,b+1+n);
		long long E=0,S=0;
		for(int i=1; i<=mid; i++) {
			E+=a[i];
			S+=E*b[i];
		}
		E+=delta;
		for(int i=mid+1; i<=n; i++) {
			E+=a[i];
			S+=E*b[i];
		}
		printf("%lld\n",S);
	}
}
int main() {
#ifndef LOCAL
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d %d",&n,&delta);
	bool a1=true,b1=true;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(a[i]!=1) a1=false;
	}
	
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
		if(b[i]!=1) b1=false;
	}
	mid=n/2;
	if(a1) a_all_1::solve();
	else if(b1) b_all_1::solve();
	else brute_force::solve();
}
