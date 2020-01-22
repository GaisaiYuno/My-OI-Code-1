#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("tree.in","w",stdout);
	srand(time(NULL));
	int n=150000,m=21372,q=9126;
	printf("%d %d %d\n",n,m,q);
	for(int i=1;i<=m;i++){
		printf("%d %d\n",rand()%i+1,i);
	}
	for(int i=1;i<=q;i++){
		int cmd=rand()%2+1;
		printf("%d ",cmd); 
		if(cmd==1){
			printf("%d\n",rand()%n+1);
		}else{
			printf("%d %d\n",rand()%n+1,rand()%n+1);
		}
	}
} 
