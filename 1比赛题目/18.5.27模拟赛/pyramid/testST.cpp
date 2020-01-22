#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define maxn 5000
using namespace std;
int n;
int a[maxn+5];
int st[maxn+5][20];
void st_init() {
	for(int i=1; i<=n; i++) st[i][0]=a[i];
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r) {
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
	srand(time(NULL));
	while(1){
		n=rand()%maxn+1;
		for(int i=1; i<=n; i++) a[i]=rand();
		st_init();
		int ans=0;
		int l=rand()%n+1;
		int r=rand()%n+1;
		if(l>r) swap(l,r);
		for(int i=l;i<=r;i++){
			ans=max(a[i],ans);
		}
		if(ans!=query(l,r)){
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
			break;
		}else printf("OK\n");
	}
}
