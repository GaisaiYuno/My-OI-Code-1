#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
#define maxn 15
#define INF 0x3f3f3f3f
using namespace std;
struct node{
	int x;
	int y;
	int k;
	node(){
		
	}
	node(int xx,int yy,int key){
		x=xx;
		y=yy;
		k=key;
	}
};
int n,m,p,k,s; 
int dist[2505][maxn][maxn];
int inq[2505][maxn][maxn];
int key[maxn][maxn];
int door[maxn][maxn][maxn][maxn];
const int walkx[4]={1,-1,0,0};
const int walky[4]={0,0,1,-1};
int spfa(){
	queue<node>q;
	q.push(node(1,1,key[1][1]));
	inq[key[1][1]][1][1]=1;
	memset(dist,0x3f,sizeof(dist)); 
	dist[key[1][1]][1][1]=0;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		inq[now.k][now.x][now.y]=0;
		for(int i=0;i<4;i++){
			int x=now.x+walkx[i];
			int y=now.y+walky[i];
			if(x>=1&&x<=n&&y>=1&&y<=m){ 
				if((door[now.x][now.y][x][y]>=1 && (now.k & (1<<door[now.x][now.y][x][y])) !=0)||door[now.x][now.y][x][y]==-1){
					if(dist[now.k|key[x][y]][x][y]>dist[now.k][now.x][now.y]+1){
						dist[now.k|key[x][y]][x][y]=dist[now.k][now.x][now.y]+1;
						if(!inq[now.k|key[x][y]][x][y]){
							inq[now.k|key[x][y]][x][y]=1;
							q.push(node(x,y,now.k|key[x][y]));
						} 
					} 
				}
			} 
		}
	}
	int ans=INF;
	for(int i=0;i<(1<<(p+1));i++){
		ans=min(ans,dist[i][n][m]);
	}
	if(ans==INF) return -1;
	else return ans;
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
	printf("%d\n",spfa());
} 
