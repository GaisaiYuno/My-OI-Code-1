//http://hzwer.com/3570.html
//������һ��X�ڵ㻭һ��������߽紹ֱ
//�����Ǵ�������bfs��ʱ�����������ߣ���ֹͣbfs������������һȦ��������bfs��ʱ�����������ߣ����Ǿͼ����� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int sx,sy,tx,ty;
char tmp[maxn+5];
char a[maxn+5][maxn+5]; 
int dist[2][maxn+5][maxn+5];
int mark[maxn+5][maxn+5];
//  dist[1][x][y]��ʾ�������Ҿ���������֮����㵽(x,y)����̾��룬
//dist[0][x][y]��ʾû�о��������ߣ���㵽(x,y)����̾��롣
//�����Ǵ������Ҿ��������ߺ��bfs���Ǿ�ֻ����dist[1][x][y]���������ľ���dist[1][���x][���y]��
struct node{
	int x;
	int y;
	int flag;
	node(){
		
	}
	node(int _x,int _y,int _flag){
		x=_x;
		y=_y;
		flag=_flag;
	}
};
queue<node>q;
int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,0,1,-1,0,1,-1};
void bfs(int sx,int sy){
	dist[0][sx][sy]=0;
	q.push(node(sx,sy,0));
	while(!q.empty()){
		node now=q.front();
		q.pop();
//		printf("(%d,%d) flag=%d dist=%d\n",now.x,now.y,now.flag,dist[now.flag][now.x][now.y]);
		for(int i=0;i<8;i++){
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[xx][yy]!='X'){
				if(mark[now.x][now.y]&&yy<=now.y) continue;
				if(mark[xx][yy]&&yy>now.y){
					if(dist[1][xx][yy]==INF){
						dist[1][xx][yy]=dist[0][now.x][now.y]+1;
						q.push(node(xx,yy,1));
					}
				}else{
					if(dist[now.flag][xx][yy]==INF){
						dist[now.flag][xx][yy]=dist[now.flag][now.x][now.y]+1;
						q.push(node(xx,yy,now.flag));
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++){
			a[i][j]=tmp[j];
			if(tmp[j]=='*'){
				sx=i;
				sy=j;
			}
			if(tmp[j]=='X'){
				tx=i;
				ty=j;
			}
		}
	}
	for(int i=tx;i<=n;i++){
		mark[i][ty]=1;
	}
	memset(dist,0x3f,sizeof(dist));
	bfs(sx,sy);
	printf("%d\n",dist[1][sx][sy]);
}
