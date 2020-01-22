#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int Size=101;
int map[Size][Size];
int f[Size][Size];
bool vis[Size][Size];
struct queue {
	int x,y,g,col;
} q[100001];
const int dx[]= {1,0,0,-1};
const int dy[]= {0,1,-1,0};
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(map,-1,sizeof(map));
	memset(f,0x3f,sizeof(f));
	int m,n,x,y,c,ans=0x3f3f3f3f;
	scanf("%d %d",&m,&n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d %d",&x,&y,&c);
		map[x][y]=c;	//c=1  黄色   c=0 红色   c=-1 无色 
	}
	int hd=0,tl=1,nowx,nowy;
	q[tl].x=q[tl].y=1;
	q[tl].g=0;
	q[tl].col=map[1][1];
	while(hd<tl) {
		hd++;
		for(int i=0; i<4; i++) {
			nowx=q[hd].x+dx[i];
			nowy=q[hd].y+dy[i];
			if(nowx>0 && nowx<=m && nowy>0 && nowy<=m) {
				tl++;
				q[tl].x=nowx;
				q[tl].y=nowy;
				if(map[nowx][nowy]==-1) {
					if(map[q[hd].x][q[hd].y]==-1){tl--;continue;}
					q[tl].g=q[hd].g+2;
					q[tl].col=q[hd].col;
					if(q[tl].g<f[nowx][nowy]) {
						f[nowx][nowy]=q[tl].g;
						vis[nowx][nowy]=1;
					} else {
						tl--;
					}
				} else if(q[hd].col==map[nowx][nowy]) {
					q[tl].g=q[hd].g;
					q[tl].col=q[hd].col;
					if(q[tl].g<f[nowx][nowy]) {
						f[nowx][nowy]=q[tl].g;
						vis[nowx][nowy]=1;
					} else {
						tl--;
					}
				} else {
					q[tl].col=map[nowx][nowy];
					q[tl].g=q[hd].g+1;
					if(q[tl].g<f[nowx][nowy]) {
						f[nowx][nowy]=q[tl].g;
						vis[nowx][nowy]=1;
					} else {
						tl--;
					}
				}
			}
		}
	}
	if(f[m][m]!=0x3f3f3f3f)
		printf("%d",f[m][m]);
	else
		printf("-1");
	return 0;
}
