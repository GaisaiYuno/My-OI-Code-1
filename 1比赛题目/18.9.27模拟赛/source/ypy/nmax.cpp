#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int n,q;
double a[maxn];
double sum[maxn];
double f(int s){
	return ((double)(s-1)*a[n]-sum[s-1])/s; 
}
double tri_search(){
//	double ans=0;
//	for(int i=1;i<=n;i++){
//		if(ans<f(i)){
//			ans=f(i);
//		}
//	}
//	return ans;
	int l=1,r=n;
	int mid1,mid2;
	while(l<=r){
//		printf("%d %d\n",l,r);
		mid1=l+(r-l+1)/3;
		mid2=l+(r-l+1)/3*2;
		if(mid1==mid2) break;
		if(f(mid1)<f(mid2)){
			l=mid1+1;
		}else r=mid2-1;
	}
	return max(f(l),f(r));
}

int main(){
//	freopen("nmax.in","r",stdin);
//	freopen("nmax.out","w",stdout);
	int cmd,x;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d",&x);
			a[++n]=x;
			sum[n]=a[n]+sum[n-1];
		}else{
			printf("%.10f\n",tri_search());
		}
	}
}
