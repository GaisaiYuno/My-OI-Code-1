#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x;
int main(){
	scanf("%d",&x);
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			if(i%j==0&&i*j>x&&i/j<x){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("-1\n");
} 
