#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000 
using namespace std;
typedef long double db;
inline db C2(int n){
	return (db)n*(n-1)/2; 
}
int n;
db f[maxn+5];
db sumf[maxn+5];
int main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x=n-i+1; 
		f[i]=(1-sumf[i-1])*x/C2(x*2); 
		sumf[i]=sumf[i-1]+f[i];
	}
	printf("%.6Lf\n",1-sumf[n-1]);
}
