#include<iostream>
#include<cstdio>
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

int n,m;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k>0){
		if(k&1)ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	printf("%lld\n",(m+1)*fast_pow(2,n));
}
