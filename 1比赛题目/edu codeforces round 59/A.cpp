/*
Problem:
Source:Educational Codeforces Round 59 (Rated for Div. 2)
Description:
*/
#include<iostream>
#include<cstdio>
#define maxn 305
using namespace std;
int q,n;
int a[maxn];
int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++) scanf("%1d",&a[j]);
		if(n==2&&a[1]>=a[2]) printf("NO\n");
		else{
			printf("YES\n");
			printf("%d\n",2);
			printf("%d ",a[1]);
			for(int j=2;j<=n;j++){
				printf("%d",a[j]);
			}
			printf("\n");
		}
	}
}

