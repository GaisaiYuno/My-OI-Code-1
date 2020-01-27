#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
int t;
long long n,m;
long long x1,y1,x2,y2;
long long x3,y3,x4,y4;
long long sum[maxn][maxn];
long long wsum,bsum;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%I64d %I64d",&n,&m);
		scanf("%I64d %I64d %I64d %I64d",&x1,&y1,&x2,&y2);
		scanf("%I64d %I64d %I64d %I64d",&x3,&y3,&x4,&y4);
		swap(n,m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i%2) sum[i][j]=!(j%2);
				else sum[i][j]=(j%2);
			}
		}
		for(int i=x1;i<=x2;i++){
			for(int j=y1;j<=y2;j++){
				sum[i][j]=0;
			}
		}
		for(int i=x3;i<=x4;i++){
			for(int j=y3;j<=y4;j++){
				sum[i][j]=1;
			}
		}
		wsum=bsum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(sum[i][j]==0) wsum++;
				else bsum++;
			}
		}
		printf("%I64d %I64d\n",wsum,bsum);
	}
}
