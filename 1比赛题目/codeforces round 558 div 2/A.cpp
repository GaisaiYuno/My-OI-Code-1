#include<iostream>
#include<cstdio>
using namespace std;
int n,m; 
int main(){
	scanf("%d %d",&n,&m);
	if(m==0) printf("1\n");
	else if(m<=n/2) printf("%d\n",m);
	else printf("%d\n",n-m);
}

