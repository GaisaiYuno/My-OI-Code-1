/*
[El Psy Congroo]
For Selina

Problem:D
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1005
#define maxp 15
using namespace std;
int n,m,t;
struct node {
	int x;
	int y;
	int t;
	node() {

	}
	node(int xx,int yy,int d) {
		x=xx;
		y=yy;
		t=d;
	}
};
const int walkx[4]= {1,-1,0,0},walky[4]= {0,0,1,-1};
int s[maxp];
queue<node>q1[maxp];
queue<node>q2[maxp];
char graph[maxn][maxn];
int vis[maxn][maxn];
int expand(int p) {
	int newx=0;
	while(!q2[p].empty()) {
		node x=q2[p].front();
		q2[p].pop();
		x.t=0;
		q1[p].push(x);
	}
	while(!q1[p].empty()) {
		node x=q1[p].front();
		q1[p].pop();
		if(x.t==s[p]) {
			q2[p].push(x);
			continue;
		}
		for(int i=0; i<4; i++) {
			int xx=x.x+walkx[i];
			int yy=x.y+walky[i];
			if(xx<1||yy<1||xx>n||yy>m||graph[xx][yy]=='#'||vis[xx][yy]!=0||x.t+1>s[p]) continue;
			newx++;
			q1[p].push(node(xx,yy,x.t+1));
			vis[xx][yy]=p;

		}
	}
	if(newx>=1) return 1;
	else return 0;
}

int count[maxp];
char tmp[maxn];
int main() {
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1; i<=t; i++) scanf("%d",&s[i]);
	for(int i=1; i<=n; i++) {
		scanf("%s",tmp+1);
		for(int j=1; j<=m; j++) {
			graph[i][j]=tmp[j];
			if(graph[i][j]>='0'&&graph[i][j]<='9') {
				vis[i][j]=graph[i][j]-'0';
				q2[graph[i][j]-'0'].push(node(i,j,0));
			}
		}
	}
	while(1) {
		int flag=0;
		for(int i=1; i<=t; i++) {
			flag+=expand(i);
		}
		if(flag==0) break;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			count[vis[i][j]]++;
		}
	}
	for(int i=1; i<=t; i++) {
		printf("%d ",count[i]);
	}
}

