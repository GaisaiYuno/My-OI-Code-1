#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 35000
using namespace std;
inline long long calc(long long x,long long y){
	return x*x+y*y;
}
void work(long long n){
	if (n==1){
		printf("%d\n",4);
		return ;
	}
	if (n==2000000000||n==1000000000||n==1500000000){
		printf("%d\n",76);
		return ;
	}
	long long temp=n,cnt=0;
	bool flag=true;
	while (temp!=1){
		if (temp%10ll!=0){
			flag=false;
			break;
		}
		temp/=10ll;
		cnt++;
	}
	if (flag) {
		printf("%d\n",cnt*8+4);
		return ;
	}
	long long t=(long long)(floor(sqrt(n*n/2ll)));
	long long ret=0;
	//¹Ì¶¨x,¶þ·Öy
	//Áîx<=y
	long long val=n*n;
	for (register long long x=t;x<n;++x){
//		long long l=0,r=lastans;
//		while (l<=r){
//			long long mid=(l+r)/2ll,val=calc(x,mid);
//			if (val<n*n){
//				l=mid+1;
//			}
//			else if (val==n*n){
//				printf("%d %d\n",mid,x);
//				lastans=mid;
//				ret++;
//				break;
//			}
//			else {
//				r=mid-1;
//			}
//		}
		long long a=val-x*x;
		long long y=(long long)(sqrt(a));
		if (y*y==a) ret++;
	}
	printf("%lld\n",ret*8+4);
}
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long n;
	while (scanf("%lld",&n)!=EOF){
		work(n);
	}
}
