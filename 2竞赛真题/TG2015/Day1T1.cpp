#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n;
int a[maxn][maxn];
int main(){
	scanf("%d",&n);
	int x=1;
	int y=n/2+1;
	for(int i=1;i<=n*n;i++){
		a[x][y]=i;
		if(x>1&&y<n&&a[x-1][y+1]!=0){
			x++;
		}else if(y+1>n&&x-1<=0){
			x++;
		}else{
			x--;
			y++;
			if(x<=0) x=n;
			if(x>n) x=1;
			if(y<=0) y=n;
			if(y>n) y=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
} 
