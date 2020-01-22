#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005 
using namespace std;
int n;
int a[maxn];
int b[maxn];
int da[maxn];
int db[maxn];
int is_eqal(int *a,int *b,int sz){
	sort(a+1,a+1+sz);
	sort(b+1,b+1+sz);
	for(int i=1;i<=sz;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<n;i++){
		da[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		db[i]=b[i+1]-b[i];
	}
	if(a[1]!=b[1]||a[n]!=b[n]){
		printf("No\n");
	}else{
		if(is_eqal(da,db,n-1)) printf("Yes\n");
		else printf("No\n");
	} 
}

