#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 300000
using namespace std;
int t;
int n;
int a[maxn+5],b[maxn+5];
bool eqal(int *a,int *b){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
} 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
//		b[n+1]=-INF;
		int lb=1;
		for(int i=1;i<=n;i++){
			if(b[i]>b[i+1]||i==n){
				sort(a+lb,a+i+1);
				lb=i+1;
			}
		}
		if(eqal(a,b)) printf("YES\n");
		else printf("NO\n"); 
	}
}

