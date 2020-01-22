#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,m;
int sum[maxn];
int main(){
	int l,r;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l,&r);
		sum[l]++;
		sum[r+1]--;
	}
	for(int i=1;i<=m+1;i++){
		sum[i]+=sum[i-1]; 
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(sum[i]==0) cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++){
		if(sum[i]==0) printf("%d ",i);
	}
} 
