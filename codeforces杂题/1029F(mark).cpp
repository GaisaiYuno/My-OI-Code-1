#include<iostream>
#include<cstdio>
#define INF 0x7fffffffffffffff
using namespace std;
long long a,b;
long long s=0;
int check(long long x,long long y){
	for(long long i=x;i>=1;i--){//枚举小矩形边长，注意从大到小枚举，可更快找到 
		if(a%i==0&&a/i<=y) return 1;
		if(b%i==0&&b/i<=y) return 1;
	}
	return 0;
}
int main(){
	cin>>a>>b;
	s=a+b;
	long long ans=INF;
	for(long long i=1;i*i<=s;i++){//暴力枚举大矩形边长 
		if(s%i==0){
			long long x=i;
			long long y=s/i;
			if(check(x,y)){
				ans=min(ans,2*x+2*y);
			}
		}
	}
	cout<<ans;
}
