#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
using namespace std;
struct node{
	int x;
	int y;
	int step;
	int key;//二进制存钥匙串 
};
node queue[500005];
node now,nex;
char map[maxn][maxn];
int used[maxn][maxn][1025];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int n,m,maxt;
int sx,sy,ex,ey;
int bfs(){
    int head=0,tail=0;
	queue[0].x=sx;
	queue[0].y=sy;
	queue[0].step=0;
	queue[0].key=0;
	memset(used,0,sizeof(used));	
	used[sx][sy][0]=1;
	do{
		now=queue[head];
		for(int i=0;i<4;i++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			nex.key=now.key;
			nex.step=now.step;
			if(nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=m&&map[nex.x][nex.y]!='*'&&nex.step+1<maxt){
				if(map[nex.x][nex.y]=='^'){
				    return nex.step+1;//nex.step+1
				}
				if(map[nex.x][nex.y]>='a'&&map[nex.x][nex.y]<='j'){
					int tmp=map[nex.x][nex.y]-'a';
					/*if((nex.key&(1<<tmp))==0)*/ nex.key=(nex.key|(1<<tmp)); 
					/*判断门是否会打开 用&    说明可以打开
                     将钥匙加入钥匙串用| */
				}
				if(map[nex.x][nex.y]>='A'&&map[nex.x][nex.y]<='J'){
					int tmp=map[nex.x][nex.y]-'A';
					if((nex.key&(1<<tmp))==0) continue; 
				}
				if(used[nex.x][nex.y][nex.key]==1) continue;	
				used[nex.x][nex.y][nex.key]=1;
				tail++;
			 	queue[tail].x=nex.x;
				queue[tail].y=nex.y;
				queue[tail].key=nex.key;
				queue[tail].step=nex.step+1;
			    printf("(%d,%d) key=%d t=%d\n",nex.x,nex.y,nex.key,nex.step) ;
			}
		} 
		head++;
	}while(head<=tail);
	return -1;
}
int main(){
	while(cin>>n>>m>>maxt){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
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
/*
4 5 17
@A.B.
a*.*.
*..*^
c..b*

4 5 16
@A.B.
a*.*.
*..*^
c..b*
*/
