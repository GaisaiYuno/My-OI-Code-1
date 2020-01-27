/*
For Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
map<long long,int>dist;
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

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}
	if(x==0){
		putchar('0');
		return;
	}
	if(x>0){
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

long long n;
long long bin_search(long long x){
	long long l=0,r=100000;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(mid*(mid+1)/2>=x){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
long long solve(long long x){
	if(x<0) x=-x;
	long long k=bin_search(x);
	
	long long sum=(k+1)*k/2;
	if(sum==x) return k;
	else if((sum-x)%2==1){
		if(k%2==1) return k+2;
		else return k+1;
	} 
	else{
		return k;
	}
}
int main(){
	scanf("%lld",&n);
	printf("%lld\n",solve(n));
}
