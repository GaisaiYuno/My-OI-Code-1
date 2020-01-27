#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n%3==0){
		printf("%d %d %d\n",1,1,n-2);
	}else if(n%3==1){
		printf("%d %d %d\n",1,1,n-2);
	}else{
		printf("%d %d %d\n",1,2,n-3);	
	}
} 
