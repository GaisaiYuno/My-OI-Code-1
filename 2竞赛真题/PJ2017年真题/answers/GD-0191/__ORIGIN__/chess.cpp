#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node{
	int x, y;
};

const int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int w[101][101], m[101][101], mc[101][101];
bool bm[101][101];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int M,N;
	scanf("%d%d",&M,&N);
	for (int i=1; i<=M; i++) for (int j=1; j<=M; j++) m[i][j]=2147483647;
	for (int i=0; i<N; i++){
		int x, y, z;
		scanf("%d%d%d",&x,&y,&z);
		w[x][y]=z+1;
	}
	queue<Node> q;
	Node first; first.x=1; first.y=1; m[1][1]=0; bm[1][1]=0;
	q.push(first);
	while (!q.empty()){
		Node x=q.front(); q.pop();
		if (x.x==M && x.y==M) {
			printf("%d",m[x.x][x.y]);
			
			fclose(stdout);
			return 0;
		}
		for (int d=0; d<4; d++){
			int xx=x.x+fx[d][0];
			int yy=x.y+fx[d][1];
			if (xx>0 && yy>0 && xx<=M && yy<=M){
				Node now; now.x=xx; now.y=yy;
				int n_m=m[x.x][x.y]; bool n_bm=0;
				if (!w[xx][yy]) {
					if (!bm[x.x][x.y]){
						n_m+=2;
						n_bm=1;
					}else continue;
				}else if (w[xx][yy]!=w[x.x][x.y] && !(bm[x.x][x.y] && mc[x.x][x.y]==w[xx][yy])) n_m++;
				if (n_m<m[xx][yy]){
					if (n_bm) mc[xx][yy]=w[x.x][x.y];
					bm[xx][yy]=n_bm;
					m[xx][yy]=n_m;
					q.push(now);
				}else if(n_m==m[xx][yy] && !n_bm && bm[xx][yy]){
					bm[xx][yy]=n_bm;
					m[xx][yy]=n_m;
				}
			}
		}
	}
	printf("-1\n");
	
	fclose(stdout);
	return 0;
}
