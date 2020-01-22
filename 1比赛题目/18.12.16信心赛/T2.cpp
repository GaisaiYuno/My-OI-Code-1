//http://111.230.183.91:8080/problem/322
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 35
using namespace std;
char s[maxn];
int len;
void solve(long long n,long long k){
//	printf("%d %d\n",n,k);
	if(k==len){
		printf("%c",s[n]);
		return;
	}
	if(n<=k/2) solve(n,k/2);
	else if(n==k/2+1) solve(k/2,k/2);
	else solve(n-k/2-1,k/2);
}

long long n;
int main(){
	scanf("%s",s+1);
	scanf("%lld",&n);
	len=strlen(s+1);
	long long all=len;
	while(all<n){
		all=all*2;
	}
	solve(n,all);
}
