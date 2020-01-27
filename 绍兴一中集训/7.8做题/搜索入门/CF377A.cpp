#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 500
using namespace std;
char tmp[maxn+5];
char a[maxn+5][maxn+5];
int n,m,k,s;
 
struct node{
	int x;
	int y;
	node(){
		
	}
	node(int _x,int _y){
		x=_x;
		y=_y;
	}
};
int vis[maxn+5][maxn+5];
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void bfs(int sx,int sy){
	int cnt=0;
	queue<node>q;
	q.push(node(sx,sy));
	vis[sx][sy]=1;
	cnt++;
	if(cnt==s-k) return;//注意只有1个的特判 
	while(!q.empty()){
		node now=q.front();
		q.pop();
//		printf("%d %d %d\n",cnt,now.x,now.y);
		for(int i=0;i<4;i++){
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==0&&a[xx][yy]=='.'){
				q.push(node(xx,yy));
				vis[xx][yy]=1;//为了防止重复更新，放入队列时就要更新vis 
				cnt++;
				if(cnt==s-k) return;
			}
		}
	}
}
 
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++) a[i][j]=tmp[j];
	}
	int sx,sy;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				s++;
				sx=i;
				sy=j;
			}
		}
	}
	bfs(sx,sy);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'&&!vis[i][j]){
				a[i][j]='X';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}

