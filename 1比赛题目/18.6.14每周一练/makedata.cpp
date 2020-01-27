#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
//#define maxn 100005
//#define maxm 2000005
#define maxn 5
#define maxm 10
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1;
	int m=rand()%maxm+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		int c;
		if(m>0){
			c=rand()%m%n+1;
		    m-=c;
		}else c=0; 
		printf("%d ",c);
		for(int j=1;j<=c;j++) printf("%d ",rand()%n+1);
		printf("\n");
	}
	printf("%d\n",rand()%n+1);
} 
