#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 1005
#define maxm 1005
#define maxt 10
using namespace std;
int t;
int n,m;
int random(int n){
	return rand()%n+1;
}
int x1,y1,x2,y2;
int x3,y3,x4,y4;
int main(){
	srand(time(NULL));
	t=random(maxt);
	printf("%d\n",t);
	while(t--){
		n=random(maxn);
		m=random(maxm);
		printf("%d %d\n",n,m);
		x1=random(m);
		y1=random(n);
		x2=random(m);
		y2=random(n);
		x3=random(m);
		y3=random(n);
		x4=random(m);
		y4=random(n);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		if(x3>x4) swap(x3,x4);
		if(y3>y4) swap(y3,y4);
		printf("%d %d %d %d\n",x1,y1,x2,y2);
		printf("%d %d %d %d\n",x3,y3,x4,y4);
		printf("\n");
	} 
}
