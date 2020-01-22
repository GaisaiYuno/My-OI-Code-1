#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int n,q;
int a[maxn+5];
int main(){
	int l,r,x;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d %d",&x,&l,&r);
		l++;
		r++;
		int ans=0;
		for(int j=l;j<=r;j++){
			ans=max(ans,x^a[j]);
		} 
		printf("%d\n",ans);
	}
}

