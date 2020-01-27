#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 8
#define maxm 8
#define maxs 1000000000
using namespace std;
int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL));
	int n=random(maxn);
	int m=random(maxn);
	int x=random(n);
	int y=random(m);
	int l=random(n*n);
	int r=random(n*n);
	printf("%d %d %d %d %d %d\n",n,m,x,y,l,r);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==x&&j==y){
				putchar('.');
				continue;
			} 
			int t=random(5);
			if(t!=1)putchar('.');
			else putchar('*');
		}
		putchar('\n');
	}
}
