#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 105 
using namespace std;
int n;
int p[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++) scanf("%d",&p[i]); 
	sort(p+1,p+1+n/2);
	int sum_black=0;
	int sum_white=0;
	for(int i=1;i<=n/2;i++){
		sum_white+=abs(p[i]-2*i);
	}
	for(int i=1;i<=n/2;i++){
		sum_black+=abs(p[i]-(2*i-1));
	}
	printf("%d\n",min(sum_black,sum_white));
	
} 
