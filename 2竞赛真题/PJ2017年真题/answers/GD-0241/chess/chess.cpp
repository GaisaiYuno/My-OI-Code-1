#include <cstdio>
#include <cstring>
#include <deque>
#define bfx bfs.front().x
#define bfy bfs.front().y
#define bfcol bfs.front().col
using namespace std;
struct State{
	int x, y, col;
	State operator = (State a){
		x=a.x; y=a.y; col=a.col;
		return *this;
	} 
};
const int MX[4]={1,0,-1,0}, MY[4]={0,1,0,-1};
int cost[105][105][2]; //0 -> 红，1 -> 黄 
char color[105][105];
bool vis[105][105][2];
deque<State> bfs;
int getnum(char x){
	return x=='Y';
}
State makestate(int x, int y, int col){
	State a;
	a.x=x;
	a.y=y;
	a.col=col;
	return a;
}
void bfspush(int x, int y, int col){
	vis[x][y][col]=1;
	if(!bfs.empty() and cost[x][y][0]<cost[bfx][bfy][getnum(bfcol)])
		bfs.push_front(makestate(x, y, col));
	else
		bfs.push_back(makestate(x, y, col));
}
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	int i, j;
	int n, m;
	int x, y, c;
	int tox, toy;
	State ts;
	
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			cost[i][j][0]=cost[i][j][1]=100000000; 
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &x, &y, &c);
		if(c==0)
			color[x][y]='R';
		else
			color[x][y]='Y';
	}
	bfs.push_back(makestate(1, 1, getnum(color[1][1])));
	cost[1][1][getnum(color[1][1])]=0;
	while(!bfs.empty()){
		ts=bfs.front();
		bfs.pop_front();
		vis[ts.x][ts.y][ts.col]=0;
		for(i=0; i<4; i++){
			tox=ts.x+MX[i];
			toy=ts.y+MY[i];
			//如果有一个格子有颜色且可用 
			if(tox>=1 and tox<=n and toy>=1 and toy<=n and (color[ts.x][ts.y] or color[tox][toy])){
				//如果下一个格子没有颜色 
				if(!color[tox][toy]){
					if(cost[ts.x][ts.y][ts.col]+2+ts.col<cost[tox][toy][0]){
						cost[tox][toy][0]=cost[ts.x][ts.y][ts.col]+2+ts.col;
						if(!vis[tox][toy][0])
							bfspush(tox, toy, 0);
					}
					if(cost[ts.x][ts.y][ts.col]+2+!ts.col<cost[tox][toy][1]){
						cost[tox][toy][1]=cost[ts.x][ts.y][ts.col]+2+!ts.col;
						if(!vis[tox][toy][1])
							bfspush(tox, toy, 1);
					}
				}
				//否则
				else{
					if(ts.col==getnum(color[tox][toy])){ //如果两个格子颜色相同 
						if(cost[ts.x][ts.y][ts.col]<cost[tox][toy][ts.col]){
							cost[tox][toy][ts.col]=cost[ts.x][ts.y][ts.col];
							if(!vis[tox][toy][ts.col])
								bfspush(tox, toy, ts.col);
						}
					}
					else{ //否则 
						if(cost[ts.x][ts.y][ts.col]+1<cost[tox][toy][!ts.col]){
							cost[tox][toy][!ts.col]=cost[ts.x][ts.y][ts.col]+1;
							if(!vis[tox][toy][!ts.col])
								bfspush(tox, toy, !ts.col);
						}
					}
				} 
			}
		}
	}
	if(cost[n][n][0]^100000000 or cost[n][n][1]^100000000)
		printf("%d", min(cost[n][n][0], cost[n][n][1]));
	else
		printf("-1");
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
*/
