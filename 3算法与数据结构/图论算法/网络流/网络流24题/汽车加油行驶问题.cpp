/*
Problem:汽车加油行驶 
Source:https://www.luogu.org/problemnew/show/P4009
Description:按油量分层，分层图最短路 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 105
#define maxk 15 
#define INF 0x3f3f3f3f
using namespace std;
int n,k,a,b,c;
int graph[maxn][maxn];
int dist[maxn][maxn][maxk];
int inq[maxn][maxn][maxk];
struct node{
	int x;
	int y;
	int k;
	node(){
		
	}
	node(int xpos,int ypos,int oil){
		x=xpos;
		y=ypos;
		k=oil;
	}
	void debug(){
		printf("(%d,%d) oil=%d money=%d\n",x,y,k,dist[x][y][k]);
	}
};
queue<node>q;
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int spfa(){
	memset(dist,0x3f,sizeof(dist));
	dist[1][1][k]=0;
	inq[1][1][k]=1;
	q.push(node(1,1,k));
	while(!q.empty()){
		node now=q.front();
		q.pop();
//		now.debug();
		if(dist[now.x][now.y][now.k]==2){
			now.x=now.x;
		}
		inq[now.x][now.y][now.k]=0;
		if(graph[now.x][now.y]&&now.k!=k){//加油，加满达到k 
			if(dist[now.x][now.y][k]>dist[now.x][now.y][now.k]+a){
				dist[now.x][now.y][k]=dist[now.x][now.y][now.k]+a;
				if(!inq[now.x][now.y][k]){
					inq[now.x][now.y][k]=1;
					q.push(node(now.x,now.y,k));
				} 
			} 
			continue;
		}
		else{//设油库 
			if(dist[now.x][now.y][k]>dist[now.x][now.y][now.k]+a+c){
				dist[now.x][now.y][k]=dist[now.x][now.y][now.k]+a+c;
				if(!inq[now.x][now.y][k]){
					inq[now.x][now.y][k]=1;
					q.push(node(now.x,now.y,k));
				} 
			} 
		}
		for(int i=0;i<4;i++){
			node nex;
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			if(now.k<1) continue;
			int w=0;
			if(nex.x<now.x||nex.y<now.y) w=b;
			nex.k=now.k-1;
			if(nex.x>=1&&nex.y>=1&&nex.x<=n&&nex.y<=n){
				if(dist[nex.x][nex.y][nex.k]>dist[now.x][now.y][now.k]+w){
					dist[nex.x][nex.y][nex.k]=dist[now.x][now.y][now.k]+w;
					if(!inq[nex.x][nex.y][nex.k]){
						inq[nex.x][nex.y][nex.k]=1;
						q.push(nex);
					}
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=k;i++) ans=min(ans,dist[n][n][i]);
	return ans;
}
int main(){
	scanf("%d %d %d %d %d",&n,&k,&a,&b,&c);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	printf("%d",spfa());
}
