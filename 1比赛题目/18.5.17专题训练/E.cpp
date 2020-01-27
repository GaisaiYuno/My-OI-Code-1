#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxl 14
#define maxn 25
using namespace std;
const int walkx[4]={-1,1,0,0},walky[4]={0,0,-1,1};
//0,1,2,3 上/下/左/右
//状压用两位二进制表示 
int n,m,l,k;
int a[maxn][maxn]; 
int used[maxn][maxn][1<<maxl];
struct node{
	int head_x;
	int head_y;
	int shape; //状压,存储每一节和下一节的位置关系 
	int t;
	node(){
		
	}
	node(int x,int y,int s,int tim){
		head_x=x;
		head_y=y;
		shape=s;
		t=tim;
	}
};
node input_body(){
	int lastx,lasty;
	node ans;
	scanf("%d %d",&ans.head_x,&ans.head_y);
	ans.shape=0;
	ans.t=0;
	lastx=ans.head_x;
	lasty=ans.head_y;
	int x,y;
	for(int i=1;i<=l-1;i++){
		scanf("%d %d",&x,&y);
		for(int j=0;j<4;j++){
			if(lastx+walkx[j]==x&&lasty+walky[j]==y){
				ans.shape=ans.shape|(j<<((i-1)<<1));//前面已经用了(i-1)*2位 
				break;
			}
		}
		lastx=x;
		lasty=y;
    }
	return ans;	
	
}
int leftbit;
int getop(int x){
	if(x<2) return 1-x;//1->0
	else return 5-x;//2->3
}
node move_body(node now,int dir){
	int tmp=now.shape;
	tmp=tmp<<2;
	tmp=tmp&leftbit;//去掉左侧多余位数 
	int x=now.head_x+walkx[dir];
	int y=now.head_y+walky[dir];
	dir=getop(dir);
	tmp=tmp|dir;
	return node(x,y,tmp,now.t+1);
}
int is_onbody(int x,int y,node now){
	int tx=now.head_x;
	int ty=now.head_y;
	int ts=now.shape;
	for(int i=1;i<=l;i++){
		int dir=(now.shape>>((i-1)<<1)&3);//取出第i段方向 
		int nx=tx+walkx[dir];
		int ny=ty+walky[dir];
		if(x==nx&&y==ny) return 1;
		tx=nx;
		ty=ny; 
	}
	return 0;
} 
int is_ok(int x,int y,node now){
	if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]==0&&is_onbody(x,y,now)==0) return 1;
	else return 0;
}
int bfs(node s){
	queue<node>q;
	while(!q.empty()) q.pop();
	memset(used,0,sizeof(used));
	used[s.head_x][s.head_y][s.shape]=1;
	q.push(s);
	node now,nex;
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.head_x==1&&now.head_y==1) return now.t;
		for(int i=0;i<4;i++){
			nex.head_x=now.head_x+walkx[i];
			nex.head_y=now.head_y+walky[i];
			if(is_ok(nex.head_x,nex.head_y,now)){
				nex=move_body(now,i);
				if(used[nex.head_x][nex.head_y][nex.shape]==0){
					used[nex.head_x][nex.head_y][nex.shape]=1;
					q.push(nex);
				}
			}
		}
	}
	return -1;
}
int main(){
	int x,y;
	int cas=0;
	node start;
	while(scanf("%d %d %d",&n,&m,&l)!=EOF){
		if(n==0&&m==0&&l==0) break;
		start=input_body();
		memset(a,0,sizeof(a));
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d %d",&x,&y);
			a[x][y]=1;
		}
		leftbit=(1<<((l-1)<<1))-1;//leftbit 的右2*(l-1)位均为1 
		printf("Case %d: %d\n",++cas,bfs(start));
	}
	return 0;
}
