//http://111.230.183.91:8080/problem/10
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];
long long num[maxn*maxn*maxn+5];
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num[++m]=s[i]*s[j]+s[k];
			}
		}
	}
	sort(num+1,num+1+m);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				l=lower_bound(num+1,num+1+m,s[i]*(s[j]+s[k]))-num;
				r=upper_bound(num+1,num+1+m,s[i]*(s[j]+s[k]))-num-1;
				if(r>=l) ans+=(r-l+1);
			}
		}
	}
	printf("%lld\n",ans);
} 
