#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n; 
	scanf("%d",&n);
	//先1~n,2~n-1……共连n/2条边，代价为0 
	//再2~n,3~n-1 共连n/2条边，代价为1 
	if(n%2==0){
		printf("%d\n",n/2-1);
    }
    else printf("%d\n",n/2);
	 
} 
