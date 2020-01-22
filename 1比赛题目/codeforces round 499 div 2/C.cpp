#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m;
int a[maxn],b[maxn];
int main(){
	scanf("%d %d",&n,&m);
	double k=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		k*=(double)(a[i]-1)/a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		k*=(double)(b[i]-1)/b[i];
	}
	if(k==0){
		printf("-1");
		return 0;
	} 
	double ans=(double)m*(1-k)/k;
	if(ans<0){
		printf("-1");
		return 0;
	} 
	printf("%.7f\n",ans);v 

}
