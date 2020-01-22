#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[105];
int main(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt++;
	}
	if(cnt>=1) printf("HARD");
	else printf("EASY");
} 
