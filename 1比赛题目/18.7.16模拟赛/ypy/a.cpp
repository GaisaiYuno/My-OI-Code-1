#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 305
using namespace std;
int t,n;
int a,b,c,d;
struct node{
	int x;
	int y;
	int t;
	node(){
		
	}
	node(int xx,int yy,int step){
		x=xx;
		y=yy;
		t=step;
	}
	void debug(){
		printf("(%d,%d) t=%d\n",x,y,t);
	}
};
int used[maxn][maxn];
const int walkx[8]={-2,-2,-1,-1,1,1,2,2},walky[8]={1,-1,2,-2,2,-2,1,-1};
int check(node a){
//	if(a.x<0||a.y<0||a.x>=n||a.y>=n) return 0;
     if(a.x<0||a.y<0||a.x>n||a.y>n) return 0;
	if(used[a.x][a.y]) return 0;
	return 1;
}
int bfs(int x1,int y1,int x2,int y2){
	queue<node>q;
	q.push(node(x1,y1,0));
	node now,nex;
	while(!q.empty()){
		now=q.front();
		q.pop();
//		now.debug();
		if(now.x==x2&&now.y==y2) return now.t;
		for(int i=0;i<8;i++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
            nex.t=now.t+1;
			if(check(nex)){
				q.push(nex);
				used[nex.x][nex.y]=1;
			} 
		}
	}
	return -1;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d %d",&a,&b);
		scanf("%d %d",&c,&d);
		memset(used,0,sizeof(used));
		printf("%d\n",bfs(a,b,c,d));
	}
}
/*
3
8
0 0
7 0

100
0 0
30 50

10
1 1
1 1
*/
