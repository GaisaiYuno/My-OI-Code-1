#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mx=2e10,dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
long long m,n,p[110][110],v[110][110][2],a,b,c,ii,mn=mx;
bool pd[110][110];
void dfs(long long x,long long y,long long st,long long r,long long l){
	if(v[x][y][r]==-1)v[x][y][r]=st;
	else if(st>=v[x][y][r])return;
	else v[x][y][r]=st;
	if(x==m&&y==m){
		if(st<mn)mn=st;
		return;
	}
	long long i,j;
	for(i=0;i<4;i++){
		long long xx=x+dr[i][0];
		long long yy=y+dr[i][1];
		if(xx<1||yy<1||xx>m||yy>m||pd[xx][yy]||(r&&p[xx][yy]==-1))continue;
		pd[xx][yy]=true;
		if(p[xx][yy]==-1)
			dfs(xx,yy,st+2,1,i);
		else if(r==1)
			dfs(xx,yy,st+abs(p[x-dr[l][0]][y-dr[l][1]]-p[xx][yy]),0,i);
		else dfs(xx,yy,st+abs(p[xx][yy]-p[x][y]),0,i);
		pd[xx][yy]=false;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(p,-1,sizeof(p));
	memset(v,-1,sizeof(v));
	scanf("%lld%lld",&m,&n);
	for(ii=1;ii<=n;ii++)
		scanf("%lld%lld%lld",&a,&b,&c),p[a][b]=c;
	if(p[m][m]==-1&&p[m][m-1]==-1&&p[m-1][m]==-1)return 0;
	dfs(1,1,0,0,5);
	if(mn==mx)printf("-1");
	else printf("%lld",mn);
}
