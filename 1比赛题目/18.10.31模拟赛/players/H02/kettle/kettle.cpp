#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 2005
#define MHY_BAOLING true
#define ZYD_AK_IOI true
using namespace std;
struct node{
	int x,y;
	int max_water;
	int now_water;
	int vis;
};
inline int Abs(int x){
	return x>0?x:-x;
}
inline int Get_Dist(int x1,int y1,int x2,int y2){
	return Abs(x1-x2)+Abs(y1-y2);
}
int ex,ey,sx,sy;
bool operator < (const node &a,const node &b){
	if (Get_Dist(a.x,ex,a.y,ey)!=Get_Dist(b.x,ex,b.y,ey)){
		return Get_Dist(a.x,ex,a.y,ey)<Get_Dist(b.x,ex,b.y,ey); 
	}
	else {
		return max(a.max_water,a.now_water)<max(b.max_water,b.now_water);
	}
}
inline char gc(){
	char ch=getchar();
	while (ch!='.'&&ch!='#'){
		ch=getchar();
	}
	return ch;
}
short Map[MAXN][MAXN];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int h,w;
inline bool inside(int x,int y){
	return x>=1&&x<=h&&y>=1&&y<=w;
}
inline int bfs(){
	queue<node>Q;
	while (Q.size()) Q.pop();
	node temp;
	temp.max_water=temp.now_water=0;
	temp.x=sx,temp.y=sy;
	temp.vis=0;
	Q.push(temp);
	int answer=0x7fffffff;
	while (Q.size()){
		node fa=Q.front();
		//printf("%d %d %d %d\n",fa.x,fa.y,fa.max_water,fa.now_water);
		Q.pop();
		if (Q.size()>10000000&&answer==0x7fffffff){
			return -1;
		}
		if (fa.max_water>=answer||fa.vis>=15){
			continue;
		}
		if (fa.x==ex&&fa.y==ey){
			answer=min(answer,max(fa.max_water,fa.now_water));
//			printf("%d\n",answer);
			continue;
		}
		for (register int i=0;i<4;++i){
			node ch;
			int nx=fa.x+dx[i],ny=fa.y+dy[i];
			if (!inside(nx,ny)) continue;
			if (Map[nx][ny]==1){
				continue;
			}
			else if (Map[nx][ny]==2){
				ch.max_water=max(fa.max_water,fa.now_water);
				ch.now_water=0;
			}
			else if (Map[nx][ny]==0){
				ch.now_water=fa.now_water+1;
				ch.max_water=max(fa.max_water,ch.now_water);
			}
			ch.vis=fa.vis+1;
			ch.x=nx,ch.y=ny;
			Q.push(ch);
		}
	}
	return answer==0x7fffffff?-1:answer;
}
int X[200005],Y[200005];
int main(){
	freopen("kettle.in","r",stdin);
	freopen("kettle.out","w",stdout);
	int p,q;
	scanf("%d%d%d%d",&h,&w,&p,&q);
	for (register int i=1;i<=h;++i){
		for (register int j=1;j<=w;++j){
			Map[i][j]=(gc()=='.'?0:1);
		}
	}
	for (register int i=1;i<=p;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		Map[x][y]=2;
		X[i]=x,Y[i]=y;
	}
	for (register int i=1;i<=q;++i){
		int pos1,pos2;
		scanf("%d%d",&pos1,&pos2);
		sx=X[pos1],sy=Y[pos1];
		ex=X[pos2],ey=Y[pos2];
		printf("%d\n",bfs());
	}
}
/*
5 5 4 4
.....
..##.
.#...
..#..
.....
1 1
4 2
3 3
2 5
1 2
2 4
1 3
3 4
*/
