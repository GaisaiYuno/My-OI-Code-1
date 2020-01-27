#include<iostream>
#include<cstring>
#define maxn 105
#define maxq maxn*maxn*(1<<5)
using namespace std;
struct node{
	int x;
	int y;
	int step;
	int tre;//宝藏 
};
node queue[maxq];
node now,nex;
int n,m,k,x1,y1;
char map[maxn][maxn];
int used[maxn][maxn][(1<<5)];
int bao[maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
bool judge(int x,int y){
	if(x<1||y<1||x>n||y>m) return false;
	if(map[x][y]=='#') return false;
	return true;
}
int bfs(){
	int head=0,tail=0;
	queue[0].x=x1;
	queue[0].y=y1;
	queue[0].step=0;
	queue[0].tre|=bao[x1][y1];
//printf("'%c'(%d,%d) step=%d tre=%d\n",map[x1][y1],x1,y1,0,queue[0].tre);
	memset(used,0,sizeof(used));
	used[x1][y1][bao[x1][y1]]=1;
	do{
		now=queue[head];
		if(now.tre==((1<<k)-1)) return now.step;
		for(int i=0;i<4;i++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			nex.step=now.step+1;
			if(judge(nex.x,nex.y)){
                nex.tre=(now.tre|bao[nex.x][nex.y]);
				if(used[nex.x][nex.y][nex.tre]==1) continue;
				used[nex.x][nex.y][nex.tre]=1;
				tail++;
				queue[tail].x=nex.x;
				queue[tail].y=nex.y;
				queue[tail].step=nex.step;
				queue[tail].tre=nex.tre;
				//printf("'%c'(%d,%d) step=%d tre=%d\n",map[nex.x][nex.y],nex.x,nex.y,nex.step,nex.tre);
			}
		}
		head++;
	}while(head<=tail);
	return -1;
}
int main(){
	while(cin>>n>>m&&n!=0&&m!=0){
		memset(bao,0,sizeof(bao));//记得初始化！！！ 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			   cin>>map[i][j];
			   if(map[i][j]=='@'){
			   	    x1=i;
			   	    y1=j;
			   } 
			} 
		}
		int tx,ty;
		cin>>k;
		//cout<<((1<<k)-1)<<endl;
		for(int i=1;i<=k;i++){
			cin>>tx>>ty;
			bao[tx][ty]=(1<<(i-1));
		}
		cout<<bfs()<<endl;
	}
}
