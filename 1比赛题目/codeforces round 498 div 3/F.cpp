#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
using namespace std;
int n,m;
long long k;
long long a[maxn][maxn];
long long ans=0;
void dfs(int x,int y,long long sum){
	if(x==n&&y==m&&sum==k){
		ans++;
		return;
	}
	if(x+1<=n) dfs(x+1,y,sum^a[x+1][y]);
	if(y+1<=m) dfs(x,y+1,sum^a[x][y+1]);
}
int main(){
	scanf("%d %d %I64d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%I64d",&a[i][j]);
		} 
	}
	dfs(1,1,a[1][1]);
	printf("%I64d\n",ans);
}
