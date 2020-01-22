#include<iostream>
#include<cstdio>
#define maxn 505
using namespace std;
int n,m;
int a[maxn][maxn];
int b[maxn][maxn];
int ar[maxn],ac[maxn];
int br[maxn],bc[maxn];
void work(int cmd,int *row,int *col){
	if(cmd==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				row[i]=row[i]^a[i][j];
				col[j]=col[j]^a[i][j]; 
			} 
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				row[i]=row[i]^b[i][j];
				col[j]=col[j]^b[i][j]; 
			} 
		}
	}
}
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
	work(0,ar,ac);
	work(1,br,bc); 
	for(int i=1;i<=n;i++){
		if(ar[i]!=br[i]){
			printf("No\n");
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(ac[i]!=bc[i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n"); 
}


