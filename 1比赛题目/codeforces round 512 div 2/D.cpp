#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,k;
int main(){
	cin>>n>>m>>k;
	if((2*n*m)%k) printf("NO\n");
	else{
		long long x=n*m*2/k;
		bool flag=false;
		for(long long i=1;i*i<=x;i++){
			if(x%i==0){
				if(i<=n&&x/i<=m){
					flag=true;
					printf("YES\n");
					printf("%I64d %I64d\n",0ll,0ll);
					printf("%I64d %I64d\n",i,0ll);
					printf("%I64d %I64d\n",i,x/i);
					break;
				}
				if(x/i<=n&&i<=m){
					flag=true;
					printf("YES\n");
					printf("%I64d %I64d\n",0ll,0ll);
					printf("%I64d %I64d\n",x/i,0ll);
					printf("%I64d %I64d\n",x/i,i);
					break;
				}
			}
		}
//		if(!flag) printf("NO\n");
	}
}
