#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
#define maxn 15
using namespace std;
struct node{
	int x;
	int y;
	int k;
	int t;
	node(){
		
	}
	node(int xx,int yy,int key,int tim){
		x=xx;
		y=yy;
		k=key;
		t=tim;
	}
	void debug(){
		printf("(%d,%d) tim=%d ",x,y,t);
		cout <<"key="<<bitset<10>(k)<<endl;
	}
};
int n,m,p,k,s; 
int vis[2005][maxn][maxn];
int key[maxn][maxn];
int door[maxn][maxn][maxn][maxn];
const int walkx[4]={1,-1,0,0};
const int walky[4]={0,0,1,-1};
int bfs(){
	queue<node>q;
	q.push(node(1,1,key[1][1],0));
	vis[key[1][1]][1][1]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
//		now.debug();
		if(now.x==n&&now.y==m){
			return now.t;
		} 
		for(int i=0;i<4;i++){
			int x=now.x+walkx[i];
			int y=now.y+walky[i];
			if(x>=1&&x<=n&&y>=1&&y<=m){ 
				if(door[now.x][now.y][x][y]==0) continue;
				if((door[now.x][now.y][x][y]>=1 && (now.k & (1<<door[now.x][now.y][x][y])) !=0)||door[now.x][now.y][x][y]==-1){
					if(vis[now.k|key[x][y]][x][y]) continue;
					vis[now.k|key[x][y]][x][y]=1;
					q.push(node(x,y,now.k|key[x][y],now.t+1)); 
				}
			} 
		}
	}
	return -1;
}

int main(){
	int x1,y1,x2,y2,g;
	scanf("%d %d %d",&n,&m,&p);
	scanf("%d",&k);
	memset(door,0xff,sizeof(door));
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&g);
		door[x1][y1][x2][y2]=g;	
		door[x2][y2][x1][y1]=g;
	}
	scanf("%d",&s);
	for(int i=1;i<=s;i++){
		scanf("%d %d %d",&x1,&y1,&g);
		key[x1][y1]|=(1<<g);
	}
	printf("%d\n",bfs());
} 
