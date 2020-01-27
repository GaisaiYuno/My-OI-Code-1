#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
struct node{
	int x;
	int y;
	int step;
	int key;
};
node queue[maxn*maxn];
char map[maxn][maxn];
bool used[maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int n,m,t;
int sx,sy,ex,ey;
bool judge(int x,int y){
	if(x<1||y<1) return false;
	if(y>n||y>m) return false;
	if(map[x][y]=='*') return false;
	if(used[x][y]) return false;
	return true;
}
int bfs(){
    int head=0,tail=1;
    int tx,ty,tstep;
    memset(used,0,sizeof(used));
	queue[1].x=sx;
	queue[1].y=sy;
	queue[1].step=0;	
	used[sx][sy]=true;
	if(tx==sx&&ty==sy){
		return 0; 
	}
	while(head<tail){
		head++;
		for(int i=1;i<=4;i++){
			tx=queue[head].x+walkx[i];
			ty=queue[head].y+walky[i];
			tstep=queue[head].step;
			if(tstep>t) return -1;
			if(tx==ex&&ty==ey){
				if(tstep>t) return -1;
				else{
					return tstep;
				}
			}
			if(judge(tx,ty)){
				if(map[tx][ty]>='A'&&map[tx][ty]<='J'){
					if(queue[tail].key!=(queue[tail].key|(1<<(map[tx][ty]-'A')))) continue;
					tail++;
				    queue[tail].x=tx;
				    queue[tail].y=ty;
				    queue[tail].key=queue[head].key;
				    queue[tail].step=tstep+1;
				}
				else if(map[tx][ty]>='a'&&map[tx][ty]<='j'){
					tail++;
				    queue[tail].x=tx;
				    queue[tail].y=ty;
				    queue[tail].key=1<<(map[tx][ty]-'A');;
				    queue[tail].step=tstep+1;
				}
				else {
					tail++;
			 	    queue[tail].x=tx;
					queue[tail].y=ty;
					queue[tail].key=queue[head].key;
					queue[tail].step=tstep+1;
				}
			}
		} 
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					sx=i;
					sy=j;
				}
				if(map[i][j]=='^'){
					ex=i;
					ey=j;
				}
			}
		}
		cout<<bfs()<<endl;
	}
}
