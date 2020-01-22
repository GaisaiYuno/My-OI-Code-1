#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int q;
long long solve(long long x,long long y,long long k){
	if(x>k||y>k) return -1;
	if((x+y)&1) return k-1;
	else{
		if((k&1)!=(max(x,y)&1)) return k-2;
		else return k;
	}
} 
int main(){
	long long x,y,k;
	scanf("%d",&q);
	while(q--){
		scanf("%I64d %I64d %I64d",&x,&y,&k);
		printf("%I64d\n",solve(x,y,k));
	} 
}
