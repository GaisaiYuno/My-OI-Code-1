#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 1005
using namespace std;
map<int,int>ma;
int n;
int a[maxn]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0) a[i]--;
	}
	for(int i=1;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d",a[n]);
	
} 
