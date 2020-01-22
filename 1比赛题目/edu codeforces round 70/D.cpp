#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxsqrtn 100000
using namespace std;
typedef long long ll;
int t,n;
ll sum[maxsqrtn+5];
int cnt[maxsqrtn+5];
void divide(int n){
	while(n>0){
		int x=upper_bound(sum+1,sum+1+maxsqrtn,n)-sum-1;
		cnt[x]++;
		n-=sum[x];
	}
}

int s[maxsqrtn+5];
int main(){
	for(ll i=1;i<=maxsqrtn;i++){
		sum[i]=i*(i-1)/2;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=maxsqrtn;i++) cnt[i]=0;
		divide(n);
		int last=0;
		int sz=0;
		for(int i=1;i<=maxsqrtn;i++){
			if(cnt[i]){
				for(int j=1;j<=i-last;j++) s[++sz]=3;
				for(int j=1;j<=cnt[i];j++) s[++sz]=1;
				last=i;
			}
		}
		for(int i=sz;i>=1;i--) putchar('0'+s[i]);
		putchar('7');
		putchar('\n');
	}
}

