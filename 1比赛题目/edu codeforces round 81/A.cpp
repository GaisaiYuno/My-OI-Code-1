#include<iostream>
#include<cstdio>
using namespace std;
int t;
int n; 
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%2==1){
			printf("7");
			n-=3;
		}
		for(int i=1;i<=n/2;i++) printf("1");
		printf("\n");
	}
}

