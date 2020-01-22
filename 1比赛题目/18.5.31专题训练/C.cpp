#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define INF 0x7fffffff
using namespace std;
int n;
int tmp[maxn];
int a[maxn][maxn]; 
long long sum[maxn][maxn];
void ini(){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
}
long long query(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int ptr=1;
		while(scanf("%d",&tmp[ptr++]),ptr<=n*n) ;
	    ptr=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=tmp[ptr++];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		ini();
		long long ans=-INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int size=1;size<=n;size++){
					if(i+size-1>n||j+size-1>n) continue;
					ans=max(ans,query(i,j,i+size-1,j+size-1)); 
					printf("(%d %d)->(%d %d)=%d\n",i,j,i+size-1,j+size-1,query(i,j,i+size-1,j+size-1));
				} 
			}
		}
		printf("%I64d\n",ans);
	} 
} 
