#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int main(){
	freopen("data.txt","w",stdout);
	srand((unsigned)time(NULL));
	int t=rand()%20+1;
	while(t--){ 
	int n,m,s,k,p;
	n=rand()%50+1;
	m=rand()%50+1;
	s=rand()%10+1;
	k=rand()%50+1;
	p=rand()%10+1;
	int x1,y1,x2,y2;
	int maxp;
	printf("%d %d %d\n",n,m,p);
	printf("%d\n",k);
	while(k--){
		int i,tp;
	    x1=rand()%n+1;
		y1=rand()%m+1;
		i=rand()%4;
		x2=x1+walkx[i];
		y2=y1+walky[i];
		tp=rand()%p;
		printf("%d %d %d %d %d\n",x1,y1,x2,y2,tp);
		maxp=max(maxp,tp);
	} 
	printf("%d\n",s);
	while(s--){
		x1=rand()%n+1;
		y1=rand()%m+1;
		printf("%d %d %d\n",x1,y1,rand()%maxp+1);
	}
	} 
	
} 
