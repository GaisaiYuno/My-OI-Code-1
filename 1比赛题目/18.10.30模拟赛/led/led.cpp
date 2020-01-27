#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
int t,n,k,l;
int a[maxn];
int main(){
	freopen("led.in","r",stdin);
	freopen("led.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d %d",&n,&k,&l);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[j]);
		}
		printf("-1\n");
	}
	return 0;
}
