#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];
map<long long,long long>num;
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num[s[i]*s[j]+s[k]]++;
				printf("%lld\n",s[i]*s[j]+s[k]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans+=num[s[i]*(s[j]+s[k])];
			}
		}
	}
	printf("%lld\n",ans);
} 
