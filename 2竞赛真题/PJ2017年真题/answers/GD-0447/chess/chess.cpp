#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
struct p{int x,y,co;};
int n,m,ans,co[101][101],dis[101][101][6];
bool inq[101][101][5];
queue<p>q;
int Abs(int x){return x>=0?x:-x;}
int main(){
	freopen("chess.in","rb",stdin);
	freopen("chess.out","wb",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		co[x][y]=c+1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j][0]=dis[i][j][1]=dis[i][j][3]=dis[i][j][4]=0x7fffffff;
	q.push((p){1,1,co[1][1]});
	dis[1][1][0]=dis[1][1][1]=dis[1][1][3]=dis[1][1][4]=0;
	inq[1][1][co[1][1]]=true;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,c=q.front().co;
		q.pop();
		for(int i=0;i<4;i++){
			int xd=x+d[i][0],yd=y+d[i][1];
			if(xd<1||xd>n||yd<1||yd>n)continue;
			if(c>0&&!co[xd][yd]&&dis[x][y][c+2]+2<dis[xd][yd][-c+2]){
				dis[xd][yd][-c+2]=dis[x][y][c+2]+2;
				if(!inq[xd][yd][c+2]){
					q.push((p){xd,yd,-c});
					inq[xd][yd][c+2]=true;
				}
			}
			if(co[xd][yd]&&min(dis[x][y][0],min(dis[x][y][1],dis[x][y][3]))+(Abs(c)!=co[xd][yd]?1:0)<dis[xd][yd][3]){
				dis[xd][yd][3]=min(dis[x][y][0],min(dis[x][y][1],dis[x][y][3]))+(Abs(c)!=co[xd][yd]?1:0);
				if(!inq[xd][yd][c+2]){
					q.push((p){xd,yd,co[xd][yd]});
					inq[xd][yd][co[xd][yd]+2]=true;
				}
			}
		}
		inq[x][y][c+2]=false;
	}
	ans=max(max(dis[n][n][0],dis[n][n][1]),max(dis[n][n][3],dis[n][n][4]));
	printf("%d\n",ans==0x7fffffff?-1:ans);
}
