#include<iostream>
#include<cstdio> 
#include<cmath>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		int sum=0;
		int sq=(int)sqrt(n);
		for(int i=2;i<=sq;i++){
		    if(n%i==0) sum=sum+i+(n/i);
		}
		if(sqrt(n)==1.0*sq) sum-=sq;
		printf("%d\n",sum+1);
	}
}
