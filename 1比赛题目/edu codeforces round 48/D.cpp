#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,m;
int a[maxn],b[maxn];
int ans[maxn][maxn];
int main(){
	scanf("%d %d",&n,&m);
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum1=sum1^a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		sum2=sum2^b[i];
	}
	if(sum1==sum2){
		printf("YES\n");
		for(int i=1;i<=n;i++) ans[i][m]=a[i];
		for(int i=1;i<=m;i++) ans[n][i]=b[i];
		int tmp=0;
		for(int i=1;i<=m-1;i++){
			tmp=tmp^b[i];
		}
		tmp=tmp^a[n];
		ans[n][m]=tmp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("NO\n");
	}
}

