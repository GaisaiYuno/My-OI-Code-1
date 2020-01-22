#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 1e10
using namespace std;
int n,m;
int a[maxn];
int x,d;
long long sum;
long long get_s(int x,int d){
	long long s=x*n;
	long long i=n;
	if(d<0) i=1;
	s+=d*(i*(i-1)/2+(n-i+1)*(n-i)/2 );
	return s;
}
int main(){
	scanf("%d %d",&n,&m);
//	for(int i=1;i<=n;i++){
//		scanf("%d",&a[i]);
//		sum+=a[i];
//	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&d);
		ans+=get_s(x,d);
	}
	printf("%.15f\n",(double)ans/n);
}
