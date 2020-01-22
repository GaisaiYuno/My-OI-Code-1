#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#define maxn 10
using namespace std;
int walkx[8]={1,1,1,-1,-1,-1,0,0};
int walky[8]={0,-1,1,0,1,-1,1,-1};
string cmd[8]={"R","RD","RU","L","LU","LD","U","D"};
struct node{
	int x;
	int y;
	int t; 
	int dir;
	node(){
		t=0; 
		dir=-1;
	}
	node(int xx,int yy){
		x=xx;
		y=yy;
		t=0;
		dir=-1; 
	} 
	node(int xx,int yy,int step,int way){
		x=xx;
		y=yy;
		t=step;
		dir=way;
	}
};
node last[maxn][maxn]; 
int used[maxn][maxn];
int check(int x,int y){
	if(x>0&&y>0&&x<=8&&y<=8&&used[x][y]==0) return 1;
	else return 0;
}
void print(int sx,int sy,node now){
	int x=now.x;
	int y=now.y;
	if(x==sx&&y==sy) return;
	else{
//		printf("%d %d\n",x,y); 
		print(sx,sy,last[x][y]);
		cout<<cmd[now.dir];
		printf("\n");
	}
}
node bfs(int sx,int sy,int ex,int ey){
	queue<node>q;
	q.push(node(sx,sy));
	used[sx][sy]=1;
	node now,nex; 
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.x==ex&&now.y==ey){
			return now;
		}
		int x,y;
		for(int i=0;i<8;i++){
			x=now.x+walkx[i];
			y=now.y+walky[i];
			if(check(x,y)){
				used[x][y]=1;
				last[x][y]=now;
				q.push(node(x,y,now.t+1,i));
			} 
		}
	}
}
int main(){
	char c1,c2;
	int y1,y2;
	int x1,x2;
	scanf("%c%d\n",&c1,&y1);
	scanf("%c%d",&c2,&y2);
	x1=c1-'a'+1;
	x2=c2-'a'+1;
//	printf("%d %d %d %d\n",x1,y1,x2,y2);
	node ans=bfs(x1,y1,x2,y2);
	printf("%d\n",ans.t);
	print(x1,y1,ans);
}
