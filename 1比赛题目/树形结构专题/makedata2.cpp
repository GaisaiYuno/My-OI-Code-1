#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 10
#define maxc 5
#define maxw 50
using namespace std;
inline int random(int n){
	int x=rand()%n;
	int k=rand()%2;
	if(k==0) return x;
	else return -x;
}
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1,m=rand()%maxm+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxw));
	}
	printf("\n%d\n",m);
	int x,c,w,y,cmd;
	for(int i=1;i<=m;i++){
		cmd=rand()%4;
		x=rand()%n+1;
		y=rand()%n+1;
		if(x>y) swap(x,y);
		w=random(maxw);
		if(cmd==0){
			printf("Q %d %d\n",x,y);
		}else if(cmd==1){
			printf("A %d %d\n",x,y);
		}else if(cmd==2){
			printf("P %d %d %d\n",x,y,w);
		}else{
			printf("C %d %d %d\n",x,y,w);
		} 
	}
}
