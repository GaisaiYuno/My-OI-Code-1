#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime> 
#define maxn 10
#define maxm 100
#define maxv 100
using namespace std;
int n,m;
int main(){
	n=rand()%maxn+1;
	m=rand()%maxm+1;
	printf("%d %d\n",n,m); 
	for(int i=1;i<=n;i++){
		printf("%d ",rand()%maxv+1);
	}
}
