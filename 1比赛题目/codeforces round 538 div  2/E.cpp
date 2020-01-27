#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
int ask1(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int ans=0;
	scanf("%d",&ans);
	return ans;
} 
int ask2(int x){
	printf("> %d\n",x);
	fflush(stdout);
	int ans=0;
	scanf("%d",&ans);
	return ans;
} 

int asks=0;
int bin_search(int l,int r){
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		asks++;
		if(ask2(mid)){
			l=mid+1;
		}else{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}

int a[62];
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b); 
}
inline int random(){
	return (long long)rand()*rand()%n+1;
}
int main(){
	srand(19260817);
	scanf("%d",&n);
	fflush(stdout);
	int x=bin_search(0,1e9+1);
//	printf("debug:%d\n",x);
	for(int i=1;i<=60-asks;i++){
		a[i]=ask1(random());
	}
	int ans=0;
	for(int i=1;i<=60-asks;i++){
		for(int j=i+1;j<=60-asks;j++){
			ans=gcd(ans,abs(a[i]-a[j]));
		}
	}
	printf("! %d %d\n",x-ans*(n-1),ans);
}

