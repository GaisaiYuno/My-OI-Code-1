#include<iostream>
#include<cstring>
#define maxn 25
#define maxm 25
using namespace std;
int m,n;
struct node {
	int x;
	int y;
	int t;
} queue[maxn*maxm];
struct dot {
	char kind;
	int used;
} map[maxn][maxm];
int x1,y1,x2,y2;
int head=0;
int tail=0;
//const int xx[4]= {1,-1,0,0},yy[4]= {0,0,1,-1};
const int xx[4]= {0,0,1,-1},yy[4]= {1,-1,0,0};
void input() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>map[i][j].kind;
			map[i][j].used=0;
			if(map[i][j].kind=='S') {
				x1=i;//注意x,y x在这里是竖的 
				y1=j;
			} else if(map[i][j].kind=='T') {
				x2=i;
				y2=j;
			}
		}
	}
}
bool judge(int x,int y) {
	if (x>=1&&y>=1&&x<=n&&y<=m&&map[x][y].used==0&&map[x][y].kind!='*') return true;
	else return false;
}
void push_node(int x,int y,int t) {
	tail++;
	queue[tail].x=x;
	queue[tail].y=y;
	queue[tail].t=t;
	map[x][y].used=1;
	//printf("(%d,%d) '%c' t=%d head=%d tail=%d \n",x,y,map[x][y].kind,t,head,tail);
	return;
}
int bfs() {
	head=0;
	tail=0;
	queue[0].x=x1;
	queue[0].y=y1;
	queue[0].t=0;
	map[x1][y1].used=1;
	int x,y,th;
	do {
		if(queue[head].x==x2&&queue[head].y==y2) {
			return queue[head].t;
		}
		for(int a=0; a<4; a++) {
			x=queue[head].x+xx[a];
			y=queue[head].y+yy[a];
			th=queue[head].t;
			if (!judge(x,y)) continue;
			else if(map[x][y].kind=='.'||map[x][y].kind== 'T') {
				push_node(x,y,th+1);
			} else {
				if(a==0||a==1) {
					if(map[x][y].kind=='-'&&(th%2==0)) {
						x+=xx[a];
						y+=yy[a];
						if(judge(x,y)) {
							push_node(x,y,th+1);

						}
					} else if(map[x][y].kind=='|'&& (th%2==1)) {
						x+=xx[a];
						y+=yy[a];
						if(judge(x,y)) {
							push_node(x,y,th+1);

						}
					} else {
						push_node(queue[head].x,queue[head].y,th+1);
					}
				} else {
					if(map[x][y].kind=='-'&&(th%2==1)) {
						x+=xx[a];
						y+=yy[a];
						if(judge(x,y)) {
							push_node(x,y,th+1);
						}
					} else if(map[x][y].kind=='|'&&(th%2==0)) {
						x+=xx[a];
						y+=yy[a];
						if(judge(x,y)) {
							push_node(x,y,th+1);
						}
					} else {
								push_node(queue[head].x,queue[head].y,th+1);
							//不能push_node(x,y   
					}
				}
			}
		}
		head++;//出队
	} while(head<=tail);
	return -1;
}
int main() {
//	freopen("testdata.txt","r",stdin);
	while(cin>>n>>m) {
		input();
		int ans=bfs();
		cout<<ans<<endl;
	}
}

