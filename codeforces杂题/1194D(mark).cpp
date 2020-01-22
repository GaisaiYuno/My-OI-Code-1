#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		if(k%3!=0){
			if(n%3!=0) printf("Alice\n");
			else printf("Bob\n");
		}else{
			n%=(k+1);
			if(n%3!=0||n==k) printf("Alice\n");
			else printf("Bob\n");
		}
	}
}

