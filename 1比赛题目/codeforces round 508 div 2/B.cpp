#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n<=2) printf("No\n");
	else{
		printf("Yes\n");
		int t1;
		if(n%2==0) t1=n/2;
		else t1=n/2+1;
		printf("%d ",t1);
		for(int i=1;i<=n;i++){
			if(i%2!=0) printf("%d ",i);
		}
		printf("\n");
		printf("%d ",n-t1);
		for(int i=1;i<=n;i++){
			if(i%2==0) printf("%d ",i);
		}
	}
}
