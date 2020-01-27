#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 5005
using namespace std;
int n,q;
int a[maxn];
int b[maxn];
int st[maxn*2][32];
void pyramid_init(){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			b[j]=b[j]^b[j+1];
		}
		for(int j=1;j<=i;j++){
			a[n-i+j]=max(a[n-i+j],b[j]);
		}
		if(i!=1)b[i]=0;
	}
}
void st_init(){
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	if(l>r) swap(l,r);
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
//	freopen("pyramid11.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	pyramid_init();
	st_init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		printf("%d\n",query(l,r));
	}
}
/*
3
8 4 1
2
2 3
1 2
*/
