#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
#define maxn 110
int a[maxn][maxn];
int dis[maxn][maxn][3];
bool inq[maxn][maxn][3];
int ax[4]={1,-1,0,0};
int ay[4]={0,0,1,-1};
struct dd{
	int x,y,col;
};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,c;
    for(int i=0;i<maxn;++i)
    for(int j=0;j<maxn;++j)dis[i][j][0]=dis[i][j][1]=dis[i][j][2]=2139062143;
	scanf("%d%d",&n,&m);
	queue<dd> q;
	while(m--){
		scanf("%d%d%d",&x,&y,&c);
		c++;
		a[x][y]=c;
	}
	dis[1][1][a[1][1]]=0;inq[1][1][a[1][1]]=1;
	q.push((dd){1,1,a[1][1]});
    while(!q.empty()){
    	dd now=q.front();
    	q.pop();
    	inq[now.x][now.y][now.col]=0;
    	for(int i=0;i<4;++i){
    		int nx=now.x+ax[i];
    		int ny=now.y+ay[i];
    		if(nx>n||nx<1||ny>n||ny<1)continue;
    		if(!a[now.x][now.y]){
    			if(!a[nx][ny])continue;
    			if(a[nx][ny]!=now.col){
    				if(dis[now.x][now.y][now.col]+1>=dis[nx][ny][a[nx][ny]])continue;
    				dis[nx][ny][a[nx][ny]]=dis[now.x][now.y][now.col]+1;
    				if(!inq[nx][ny][a[nx][ny]]){
    					inq[nx][ny][a[nx][ny]]=1;
    					q.push((dd){nx,ny,a[nx][ny]});
    				}
    			}
    			else{
    			if(dis[now.x][now.y][now.col]>=dis[nx][ny][now.col])continue;
    			dis[nx][ny][now.col]=dis[now.x][now.y][now.col];
    			if(!inq[nx][ny][now.col]){
    				q.push((dd){nx,ny,now.col});
    				inq[nx][ny][now.col]=1;
    			}
    		}
    		}else{
    			if(a[nx][ny]==a[now.x][now.y]){
    				if(dis[now.x][now.y][now.col]>=dis[nx][ny][now.col])continue;
    				dis[nx][ny][now.col]=dis[now.x][now.y][now.col];
    				if(!inq[nx][ny][now.col]){
    					q.push((dd){nx,ny,a[nx][ny]});
    					inq[nx][ny][a[nx][ny]]=1;
    				}
    			}
    			else if(!a[nx][ny]){
    				if(dis[now.x][now.y][now.col]+2>=dis[nx][ny][now.col])continue;
    				dis[nx][ny][now.col]=dis[now.x][now.y][now.col]+2;
    				if(!inq[nx][ny][now.col]){
    					q.push((dd){nx,ny,now.col});
    					inq[nx][ny][now.col]=1;
    				}
    			}else{
    				if(dis[now.x][now.y][now.col]+1>=dis[nx][ny][a[nx][ny]])continue;
    				dis[nx][ny][a[nx][ny]]=dis[now.x][now.y][now.col]+1;
    				if(!inq[nx][ny][a[nx][ny]]){
    					q.push((dd){nx,ny,a[nx][ny]});
    					inq[nx][ny][a[nx][ny]]=1;
    				}
    			}
    		}
    	}
    }
	if(!a[n][n]){
		int now=min(dis[n][n][1],dis[n][n][2]);
		if(now!=2139062143)printf("%d\n",now);
		else puts("-1");
	}else{
		if(dis[n][n][a[n][n]]!=2139062143)printf("%d\n",dis[n][n][a[n][n]]);
		else puts("-1");
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
*/
