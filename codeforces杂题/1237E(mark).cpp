#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;){
		if(i==n||i+1==n){
			printf("1\n");
			return 0;
		}
		if(i%2==1) i=i*2+2;
		else i=i*2+1;
	}
	printf("0\n");
}

