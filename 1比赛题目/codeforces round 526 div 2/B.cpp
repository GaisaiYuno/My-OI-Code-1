#include<iostream>
#include<cstdio>
#define INF 1000000000
#define maxn 1005
using namespace std;
int n;
long long a[maxn];
long long s;
long long tot=0;
long long minv=INF;
long long up(long long x,long long y){
	if(x%y==0) return x/y;
	else return x/y+1;
} 
int main(){
	scanf("%d %I64d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		tot+=a[i]; 
		minv=min(a[i],minv);
	}
	if(tot<s){
		printf("-1\n");
	}else{
		for(int i=1;i<=n;i++){
			s-=(a[i]-minv);
		}
		if(s<=0){
			printf("%I64d\n",minv);
		}else{
			printf("%I64d\n",minv-up(s,n));
		}
	}
} 
