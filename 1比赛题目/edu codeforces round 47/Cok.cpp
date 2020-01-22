#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	long long sum=0;
	long long maxv=(long long)n*(n-1)/2;
	long long minv=(long long)(n/2+1)*(n/2);
	if(n%2==0) minv-=n/2;
	while(m--){
		int x,d;
		scanf("%d %d",&x,&d);
		sum+=(long long)x*n;
		if(d>0) sum+=d*maxv;
		else sum+=d*minv;
	}
	printf("%.15f",(double)sum/n);
}
