#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 65536
#define maxm 70000
using namespace std;
int n,m;
const char c[]="UDSCI";
int main(){
	srand(time(NULL));
	n=rand()%maxn+1; 
	m=rand()%maxm+1;
	for(int i=1;i<=m;i++){
		int cmd=rand()%5;
		printf("%c ",c[cmd]);
		int sa=rand()%2;
		int sb=rand()%2;
		int a=rand()%n+1;
		int b=rand()%n+1;
		if(sa==0) printf("(%d,",a);
		else printf("[%d,",a);
		if(sb==0) printf("%d)",b);
		else printf("%d]",b);
		printf("\n");
	} 
}
