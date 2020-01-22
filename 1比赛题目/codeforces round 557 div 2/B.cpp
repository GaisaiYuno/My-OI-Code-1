#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50
using namespace std;
int n,m;
int a[maxn+5][maxn+5];
int b[maxn+5][maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>b[i][j]) swap(a[i][j],b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(a[i][j-1]>=a[i][j]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=n;j++){
			if(a[j-1][i]>=a[j][i]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(b[i][j-1]>=b[i][j]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=n;j++){
			if(b[j-1][i]>=b[j][i]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
}

