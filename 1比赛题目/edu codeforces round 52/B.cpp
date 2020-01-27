#include<iostream>
#include<cstdio>
using namespace std;
long long n,m;
int bin_search(long long x){
	long long l=0,r=200000;
	long long mid;
	long long ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(mid*(mid-1)/2>=x){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
} 
int main(){
	long long maxv,minv;
	scanf("%I64d %I64d",&n,&m);
	if(m>=n-1&&m!=0){
		minv=0;
		maxv=n-bin_search(m);
		if(maxv<0) maxv=0;
	}else if(m==0){
		maxv=n;
		minv=n;
	}else{
		minv=n-m*2;
		if(minv<0) minv=0;
		maxv=n-bin_search(m);
	}
	printf("%I64d %I64d\n",minv,maxv);
}
