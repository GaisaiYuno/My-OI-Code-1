#include<iostream>
#include<cstring>
#include<queue>
#define maxn 20
using namespace std;
int t,m,n; 
int peo_sx,peo_sy,box_sx,box_sy,end_x,end_y; 
int map[maxn][maxn];
int used[maxn][maxn][maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
struct node{
	int peo_x;
	int peo_y;
	int box_x;
	int box_y;
    int step;
    friend inline bool operator < (node a,node b){
	      return a.step>b.step;
    }
};
int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
priority_queue<node>q;
node now,nex;
void input(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=fread();
			if(map[i][j]==2){
				box_sx=i;
				box_sy=j;
			}
			if(map[i][j]==3){
				end_x=i;
				end_y=j;
			}
			if(map[i][j]==4){
				peo_sx=i;
				peo_sy=j;
			}
		}
	}
	return;
}
bool judge(int x,int y){
	if(x<1||x>m||y<1||y>n) return false;
	if(map[x][y]==1) return false;
	return true;
}
int bfs(){
	memset(used,0,sizeof(used));
	while(!q.empty()) q.pop();//清空优先队列 
	now.peo_x=peo_sx;
	now.peo_y=peo_sy;
	now.box_x=box_sx;
	now.box_y=box_sy;
	now.step=0; 
	q.push(now);
	used[peo_sx][peo_sy][box_sx][box_sy]=1;
	while(!q.empty()){ 
		now=q.top();
		q.pop();
		if(now.box_x==end_x&&now.box_y==end_y){
			return now.step;
		}
		for(int i=0;i<4;i++){
			nex.peo_x=now.peo_x+walkx[i];
			nex.peo_y=now.peo_y+walky[i]; 
			nex.box_x=now.box_x;
			nex.box_y=now.box_y;
			nex.step=now.step;
			if(judge(nex.peo_x,nex.peo_y)&&used[nex.peo_x][nex.peo_y][nex.box_x][nex.box_y]==0){
                if(nex.box_x==nex.peo_x&&nex.box_y==nex.peo_y){
                	if(judge(nex.box_x+walkx[i],nex.box_y+walky[i])&&used[nex.peo_x][nex.peo_y][nex.box_x+walkx[i]][nex.box_y+walky[i]]==0){
                		//cout<<"bfs"<<endl;
						nex.box_x+=walkx[i];
                		nex.box_y+=walky[i];
                		nex.step=now.step+1;
                		used[nex.peo_x][nex.peo_y][nex.box_x][nex.box_y]=1;
                		q.push(nex);
					}
				}
                else{
                	used[nex.peo_x][nex.peo_y][nex.box_x][nex.box_y]=1;
                	q.push(nex);
				}
			} 
		}
	} 
	return -1;
}
int main(){
	cin>>t;
	while(t--){
		input();
		cout<<bfs()<<endl;
	}
}

