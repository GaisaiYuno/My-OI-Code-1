#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
int maxa;
long long ans=0,sum=0;
long long _prev=0;
int main(){
	maxa=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ans=n;
	for(int i=1;i<=n;i++){
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]>_prev) _prev++;
	}
	ans+=a[n]-_prev;
	cout<<sum-ans;
} 
