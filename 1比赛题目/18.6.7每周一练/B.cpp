#include<iostream>
#include<cstdio>
using namespace std;
long long n,m;
int main(){
	scanf("%I64d %I64d",&n,&m);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=(m+i)/5;
		if(i>=5) ans-=i/5;
	}
	printf("%I64d\n",ans);
}
