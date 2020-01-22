//sliker
#include<iostream>
#include<cstdio>
#define maxn 55
using namespace std;
char in;
struct node1 {
	int x;
	int y;
	int t;
} queue1[maxn*maxn];
struct node2 {
	int x;
	int y;
	int t;
} queue2[maxn*maxn];
int p[maxn][maxn];//人地图
int q[maxn][maxn];//洪水地图
int n,m,c;
int x,y,x1,y1,x2,y2;
int fx,fy;
int head,tail;
int fhead,ftail;
int xx[4]= {1,-1,0,0},yy[4]= {0,0,1,-1};
void input() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>in;
			if(in=='S') {
				x1=i;
				y1=j;
				p[i][j]=1;
			}
			if(in=='D') {
				x2=i;
				y2=j;
				q[i][j]=1;
			}
			if(in=='*') {
				p[i][j]=q[i][j]=1;
				queue2[c].x=i;
				queue2[c].y=j;
				c++;
			}
			if(in=='X') {
				p[i][j]=q[i][j]=1;
			}
		}
	}
}
int bfs() {
	int k,tmp;
	do {
		int tmp=queue2[head].t;
		if(k!=tmp) break;
		for(int i=0; i<4; i++) {
			x=queue1[head].x+xx[i];
			y=queue1[head].y+yy[i];
			if(fx<=0||fy<=0||fx>n||fy>m) continue;
			if(fx==x2&&fy==y2) return k+1;
			if(!q[fx][fy]) {
				ftail++;
				queue2[ftail].x=fx;
				queue2[ftail].y=fy;
				queue2[ftail].t=queue2[fhead].t+1;
				p[fx][fy]=q[fx][fy]=1;
			}
		}
		fhead++;
	} while(fhead<=ftail);
    k=queue1[head].t;
	do {
	    tmp=queue1[head].t;
		if(k!=tmp) break;
		for(int i=0; i<4; i++) {
			x=queue1[head].x+xx[i];
			y=queue1[head].y+yy[i];
			if(x<=0||y<=0||x>n||y>m) continue;
			if(x==x2&&y==y2) return k+1;
			if(!p[x][y]) {
				tail++;
				queue1[tail].x=x;
				queue1[tail].y=y;
				queue1[tail].t=queue1[head].t+1;
				p[x][y]=1;
			}
		}
		head++;
	} while(head<=tail);
	return 0;
}
int main() {
	//freopen("slikar.in","r",stdin);
	//freopen("slikar.out","w",stdout);
	input();
	head=tail=0;
	fhead=0;
	ftail=c-1;
	queue1[0].x=x1;
	queue1[0].y=y1;
	if(!bfs()) 	cout<<"ORZ hzwer!!!";
	else cout<<queue2[tail].t;
	return 0;
}
/*
3 3
D.*
...
..S
*/
