#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a,b;
long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	cin>>n>>m>>a>>b;
	long long div=n/m;
	long long ans=0;
	if(n%m==0){
		printf("0\n");
	}else if(n>m){
		ans=min((n-(div*m) )*b,((div+1)*m-n)*a);
	    printf("%I64d\n",ans);
	}else{
		printf("%I64d\n",min((m-n)*a,n*b));
	}
} 
