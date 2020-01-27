#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 2*sqrt(1e18)
using namespace std;
long long n,h;
int is_exceed(long long x){
	if(x<=h){
//		printf("A:%d\n",x*(x+1));
		return x*(x+1)>=n*2;//x,x-1...1
	}else{
		long long k=x-h;
//		printf("B:%d\n",(h+h+k/2)*(k/2+1)+(h+k/2+1)*(h+k/2));
//		printf("C:%d\n",(h+h+k/2-1)*k/2+(h+k/2+1)*(h+k/2));
		if(k%2==1) return (h+h+k/2)*(k/2+1)+(h+k/2+1)*(h+k/2)>=n*2; //h,h+1...h+k/2,h+k/2,h+k/2-1...1 
		else return  (h+h+k/2-1)*k/2+(h+k/2+1)*(h+k/2)>=n*2; //h,h+1...h+k/2-1,h+k/2,h+k/2-1...1  
	}
}
int main(){
	scanf("%I64d %I64d",&n,&h);
	long long l=1,r=INF;
	while(l<r){
		long long mid=(l+r)>>1;
//		printf("%d %d\n",mid,is_ok(mid));
		if(is_exceed(mid)) r=mid;
		else l=mid+1;
	}
	printf("%I64d\n",l);
	
}
