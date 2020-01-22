#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[15];
int is_pair(){
	for(int i=1;i<n;i+=2){
		if(a[i]!=a[i+1]) return 0;
	}
	return 1;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		} 
		sort(a+1,a+1+n);
		if(n%2==1) printf("1\n");
		else{
			if(is_pair()) printf("0\n");
			else printf("1\n"); 
		}
	}
} 
