#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 2002
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void read2(char &x){
	x='x';
	while(x!='.'&&x!='#'){x=getchar();}
}
int H,W,P,Q;
char map[maxn][maxn];
int dis[maxn][maxn];
int ans[200005];
struct Build{
	int x,y;
}build[200005];
struct node{
	int x,y;
	int step;
	int h;
	friend bool operator < (node a,node b){
		return a.h>b.h;
	}
};
int cal(node u,node v){
	return abs(u.x-v.x)+abs(u.y-v.y);
}
void A_star(int u,int v){
	node x,y;
	x.x=build[u].x;
	x.y=build[u].y;
	x.step=0;
	y.x=build[v].x;
	y.y=build[v].y;
	x.h=cal(x,y);
	priority_queue<node>que;
	while(!que.empty()){
		x=que.top();
		que.pop();
		if()
	}
}
struct Question{
	int x,y,num;
	friend bool operator < (Question a,Question b){
		return a.x<b.x;
	}
}que[200005];
struct Questionb{
	int x,y,num;
	friend bool operator < (Question a,Question b){
		return a.y<b.y;
	}
}queb[200005];
int main(){
	read(H);read(W);read(P);read(Q);
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			read2(map[i][j]);
	int x,y;
	for(int i=1;i<=P;i++){
		read(x);read(y);
		map[x][y]='B';
		build[i].x=x;
		build[i].y=y;
	}
	for(int i=1;i<=Q;i++){
		read(que[i].x);read(que[i].y);
		que[i].num=i;
		queb[i].x=que[i].x;
		queb[i].y=que[i].y;
		queb[i].num=i;
	}
	sort(que+1;que+Q+1);
	sort(queb+1,queb+Q+1);
	for(int i=1;i<=Q;i++){
		
	}
}
