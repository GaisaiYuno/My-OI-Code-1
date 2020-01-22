#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define inf 109
#define INF (int)1e9
using namespace std;
int mp[inf][inf],vis[inf][inf][3],d[inf][inf];
const int px[]={1,-1,0,0},py[]={0,0,1,-1};

struct point{
	int x,y,col;
	point(){}
	point(int xx,int yy,int lc){
		x=xx,y=yy,col=lc;
	}
};
queue <point> q;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y]=z+1;
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			d[i][j]=INF;
		}
	}
	q.push(point(1,1,0));
	vis[1][1][0]=1;
	d[1][1]=0;
	int nx,ny,dis,l;
	while(!q.empty()){
		x=q.front().x,y=q.front().y,l=q.front().col;
		q.pop();
		vis[x][y][l]=0;
		for (int i=0;i<4;i++){
			nx=x+px[i],ny=y+py[i];
			if (nx>n || ny>n || nx<1 || ny<1){
				continue;
			}
			if (!mp[x][y]){
				if (!mp[nx][ny]){
					continue;
				}
				if (l==mp[nx][ny]){
					dis=0;
				}
				else{
					dis=1;
				}
			}
			else if (!mp[nx][ny]){
				dis=2;
			}
			else if (mp[x][y]==mp[nx][ny]){
				dis=0;
			}
			else{
				dis=1;
			}
			if (d[x][y]+dis<d[nx][ny]){
				d[nx][ny]=d[x][y]+dis;
				if (!vis[nx][ny][mp[x][y]]){
					q.push(point(nx,ny,mp[x][y]));
					vis[nx][ny][mp[x][y]]=1;
				}
			}
		}
	}
	if (d[n][n]==INF){
		printf("-1\n");
	}
	else{
		printf("%d\n",d[n][n]);
	}
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

3 4
1 1 1
1 3 1
2 2 0
3 3 1
*/
