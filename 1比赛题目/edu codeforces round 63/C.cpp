#include<iostream>
#include<cstdio>
#define maxn 300005
using namespace std;
int n,m;
long long x[maxn];
long long p[maxn];
long long y,j;
long long seg;
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b); 
} 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%I64d",&p[i]);
	y=x[1];
	for(int i=2;i<=n;i++){
		seg=gcd(seg,x[i]-x[i-1]);
	}
	for(int i=1;i<=m;i++){
		if(seg%p[i]==0){
			j=i;
			break;
		}
	}
	if(j!=0){
		printf("YES\n%I64d %I64d",y,j);
	}else{
		printf("NO\n");
	}
}

