#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1005
using namespace std;
int n,m,t;
char a[maxn][maxn];
int used[maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
struct node{
	int x;
	int y;
	int t;
	node(){} 
	node(int xx,int yy,int tim){
		x=xx;
		y=yy;
		t=tim;
	}
};
int is_check(int x,int y){
	if(x<=0||y<=0||x>n||y>m||used[x][y]==1||a[x][y]=='#') return 0;
	else return 1;
}
node bfs(int sx,int sy){
	memset(used,0,sizeof(used));
	queue<node>q;
	q.push(node(sx,sy,0));
	node now,nex;
	int tx,ty;
	int maxt=0,maxx=sx,maxy=sy;
	while(!q.empty()){
		now=q.front();
		q.pop();
	    if(now.t>maxt){
	    	maxx=now.x;
	    	maxy=now.y;
	    	maxt=now.t;
		} 
		for(int i=0;i<4;i++){
			tx=now.x+walkx[i];
			ty=now.y+walky[i];
			if(is_check(tx,ty)){
				used[tx][ty]=1;
				q.push(node(tx,ty,now.t+1));
			}
		}
	}
	return node(maxx,maxy,maxt);
}
int main(){
	char tmp[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%d %d\n",&n,&m);
		swap(n,m);
		int xx,yy;
		xx=yy=-1;
		for(int i=1;i<=n;i++){
			scanf("%s",tmp+1);
			for(int j=1;j<=m;j++){
				a[i][j]=tmp[j];
				if(a[i][j]=='.'&&xx==-1&&yy==-1){
					xx=i;
					yy=j;
				}
			}
//			getchar();
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				printf("%c",a[i][j]);
//		    }
//		    printf("\n");
//		}
		node tmp1=bfs(xx,yy);
		node tmp2=bfs(tmp1.x,tmp1.y);
		printf("Maximum rope length is %d.\n",tmp2.t);
	}
}  
