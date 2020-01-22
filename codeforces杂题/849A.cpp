#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100
using namespace std;
int n;
int a[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]%2==1&&a[n]%2==1&&n%2==1) printf("Yes\n");
	else printf("No\n"); 
}

