#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long C[75][75];
int main(){
	C[0][0]=1;
	for(int i=1;i<=70;i++){
		for(int j=0;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	} 
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		printf("%lld\n",C[n*2][n]/(n+1));
	}
}
