#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1005
using namespace std;
int n,q,t;
int a[maxn];
int st[maxn][21];
void init(){
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;j<=20;j++){
		for(int i=(1<<j);i<=n;i++){
			st[i][j]=max(st[i][j-1],st[i-(1<<(j-1))][j-1]);
		}
	} 
}
int query(int l,int r){
	int x=log2(r-l+1);
	return max(st[l+(1<<x)-1][x],st[r][x]);
}
int main(){
	int l,r;
	scanf("%d",&t);
	while(t--){ 
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		init();
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&l,&r);
			printf("%d\n",query(l,r));
		}
	} 
}
