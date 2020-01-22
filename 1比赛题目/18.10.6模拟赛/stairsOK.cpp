#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 10000000
using namespace std;
long long A,B,n;
long long L,t,m;
int check(long long x){
	long long first=A+B*(L-1) ;
	long long last=A+B*(x-1);
	if(last>t) return 0;
	if((first+last)*(x-L+1)/2<=m*t) return 1;
	else return 0;
}
int main(){
	scanf("%lld %lld %lld",&A,&B,&n);
	long long l=L,r=INF,mid;
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&L,&t,&m);
		l=L;
		r=L+1+(m*t)/(A+B*(L-1));
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)){
				ans=max(ans,mid); 
				l=mid+1;
			}
			else r=mid-1;
		}
		if(r<=L-1) ans=-1;
		else ans=r;
		printf("%lld\n",ans);
	}
} 
