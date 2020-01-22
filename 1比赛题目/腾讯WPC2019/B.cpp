#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000
using namespace std;
int t;
int n;
int a[maxn+5],b[maxn+5];
int c[maxn+5],d[maxn+5];
int cmp(int *x,int *y){
	for(int i=1;i<=n;i++){
		if(x[i]!=y[i]) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			d[i]=b[i];
		}
		sort(c+1,c+1+n);
		sort(d+1,d+1+n);
		if(!cmp(c,d)) printf("No\n");
		else{
//			bool flag=false;
//			int mid=(n+1)/2;
//			for(int i=1;i<=mid;i++){
//				if(a[i]!=b[n-i+1]) flag=true;
//			}
//			if(flag) printf("No\n");
			printf("Yes\n");
		}
	}
}

