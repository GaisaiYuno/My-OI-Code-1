#include<iostream>
#include<cstdio>
#define maxn 205
using namespace std;
const int score[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int n,na,nb;
int a[maxn];
int b[maxn];
int main(){
	scanf("%d %d %d",&n,&na,&nb);
	for(int i=0;i<na;i++) scanf("%d",&a[i]);
	for(int i=0;i<nb;i++) scanf("%d",&b[i]);
	int ansa,ansb,x,y;
	ansa=ansb=0;
	for(int i=0;i<n;i++){
		x=a[i%na];
		y=b[i%nb];
		ansa+=score[x][y];
		ansb+=score[y][x];
	}
	printf("%d %d\n",ansa,ansb);
}
