#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;
int n,m;
int a[maxn]; 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int maxk,mink;
	maxk=m+a[n];
	int sum=m;
	for(int i=1;i<=n;i++){
		sum-=(a[n]-a[i]);
	}
	if(sum>0){
		if(sum%n==0) mink=a[n]+sum/n;
		else mink=a[n]+sum/n+1;
	}
	else mink=a[n];
	printf("%d %d\n",mink,maxk);
} 
