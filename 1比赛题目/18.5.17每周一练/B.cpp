#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long pow10[12];
long long getd(int n){
	if(n<10) return n;
	long long ans=0;
	for(int i=1;i<=10;i++){
		if(n>=pow10[i])ans+=(pow10[i]-pow10[i-1])*i;
		else{
			ans+=(n-pow10[i-1]+1)*i;
			break;
		}
	}
	return ans;
	
} 
int main(){
	pow10[0]=1;
	for(int i=1;i<12;i++) pow10[i]=pow10[i-1]*10;
	int n;
	scanf("%d",&n);
	printf("%I64d",getd(n));
}
