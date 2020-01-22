/*
Problem:C
Source:Codeforces Good Bye 2018 https://codeforces.com/contest/1091/
Algorithm:
Description:
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 100005
using namespace std;
long long n,k;
long long a[maxn];
int cnt=0;
vector<long long>ans;
void div(long long n){
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			a[++cnt]=i;
			if(i!=n/i) a[++cnt]=n/i; 
		}
	}
}
int main(){
	scanf("%I64d",&n);
	div(n);
	ans.push_back(1);
	ans.push_back(n*(n+1)/2);
	for(int i=1;i<=cnt;i++){
		long long x=a[i];
		long long f=n/x*(n-x+2)/2;
		if(f!=1&&f!=n*(n+1)/2) ans.push_back(f); 
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%I64d ",ans[i]);
	}
}

