#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x,y;
};
int m,n,x,y,c,mp[101][101],dis[101][101];
bool isin[101][101],mofa[101][101];
int check(node a,node b){
	if(mp[a.x][a.y]==-1||mp[b.x][b.y]==-1||mofa[b.x][b.y])return -1;
	if(mp[a.x][a.y]==mp[b.x][b.y])return 0;
	if(mp[a.x][a.y]!=mp[b.x][b.y])return 1;
}
void spfa(){
	queue<node>q;
	node u,v;
	memset(mofa,0,sizeof(mofa));
	u.x=u.y=1;
	q.push(u);
	isin[1][1]=true;
	dis[1][1]=0;
	while(!q.empty()){
		u=q.front();
		for(int k=0;k<4;k++){
			v.x=u.x+way[k][0];
			v.y=u.y+way[k][1];
			if(v.x==0||v.x>m||v.y==0||v.y>m)continue;
			if(dis[v.x][v.y]>dis[u.x][u.y]+check(u,v)&&check(u,v)!=-1){
				dis[v.x][v.y]=dis[u.x][u.y]+check(u,v);
				if(!isin[v.x][v.y]){
					q.push(v);
					isin[v.x][v.y]=true;
				}
			}
			if(!mofa[u.x][u.y]&&mp[v.x][v.y]==-1&&!mofa[v.x][v.y]){
				if(dis[v.x][v.y]>dis[u.x][u.y]+2){
					mp[v.x][v.y]=mp[u.x][u.y];
					mofa[v.x][v.y]=true;
					dis[v.x][v.y]=dis[u.x][u.y]+2;
					if(!isin[v.x][v.y]){
						q.push(v);
						isin[v.x][v.y]=true;
					}
				}
			}
		}
		q.pop();
		isin[u.x][u.y]=false;
		if(mofa[u.x][u.y])mp[u.x][u.y]=-1;
		mofa[u.x][u.y]=false;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(mp,-1,sizeof(mp));
	memset(dis,0x7f,sizeof(dis));
	memset(isin,0,sizeof(isin));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		mp[x][y]=c;
	}
	spfa();
	printf("%d",dis[m][m]==0x7f7f7f7f?-1:dis[m][m]);
	return 0;
}
