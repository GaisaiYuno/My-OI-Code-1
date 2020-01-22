#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=110,inf=999999999;
int map[maxn][maxn],dis[maxn][maxn];
int dx[6]={0,0,0,1,-1},dy[6]={0,1,-1,0,0};
struct node{
	int x,y,d;
	int p;
};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		int x,y,c;
		cin>>x>>y>>c;
		map[x][y]=c+1;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			dis[i][j]=inf;
		}
	}
	queue<node>Q;
	dis[1][1]=0;
	Q.push((node){1,1,0,0});
	int ans=inf;
	while(!Q.empty()){
		node t=Q.front();
		Q.pop();
		if(t.x==m&&t.y==m){
			ans=min(ans,t.d);
			continue;
		}
		for(int i=1;i<=4;++i){
			int xx=dx[i]+t.x,yy=dy[i]+t.y;
			if(xx<1||xx>m||yy<1||yy>m)continue;
			if(map[t.x][t.y]==0&&map[xx][yy]!=0){
				int z=0;
				if(t.p!=map[xx][yy])z++;
				if(dis[xx][yy]>t.d+z){
					dis[xx][yy]=t.d+z;
					Q.push((node){xx,yy,t.d+z,0});
				}
			}
			else if(map[t.x][t.y]!=0){
				if(dis[xx][yy]>=t.d&&map[xx][yy]==0){
					dis[xx][yy]=t.d+2;
					Q.push((node){xx,yy,t.d+2,map[t.x][t.y]});
				}
				else if(map[xx][yy]!=0){
					if(dis[xx][yy]>t.d&&map[xx][yy]==map[t.x][t.y]){
						dis[xx][yy]=t.d;
						Q.push((node){xx,yy,t.d,0});
					}
					else if(dis[xx][yy]>t.d+1){
						dis[xx][yy]=t.d+1;
						Q.push((node){xx,yy,t.d+1,0});
					}
				}
			}
		}
	}
	if(ans!=inf)cout<<ans;
	else cout<<-1;
	return 0;
}
