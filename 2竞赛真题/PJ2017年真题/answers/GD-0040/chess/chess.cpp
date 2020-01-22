#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=100000;
int m,n,c[110][110]={0},a,b,s,x1,y1,l,sum,sign[110][110]={0};
int di[5][3]={{-1,0},{0,-1},{0,1},{1,0}};
int dfs(int x,int y,int k){
	int minn=INF;
	sign[x][y]=1;
	if(x==m && y==m)return 0;
	if(c[x][y]==INF)return INF;
	for(int i=0;i<4;i++){
		x1=x+di[i][0]; y1=x+di[i][1];
		if(sign[x1][y1]==1)continue;
		if(c[x1][y1]==0 && k==1){
			c[x1][y1]=c[x][y];
			l=dfs(x1,y1,0);
			minn=min(minn,l);
		}
		if(c[x1][y1]!=0){
			if(c[x1][y1]!=c[x][y])minn=min(minn,dfs(x1,y1,1)+1);
			if(c[x1][y1]==c[x][y])minn=min(minn,dfs(x1,y1,1));
		}
	}
	if(k==0)c[x][y]=0;
	sign[x][y]=0;
	return minn;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=m+1;j++){
			if(i==0||j==0||i==m+1||j==m+1)c[i][j]=INF;
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&s);
		c[a][b]=s+1;
	}
	sum=dfs(1,1,1);
	if(sum==INF)printf("-1");
	else printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
