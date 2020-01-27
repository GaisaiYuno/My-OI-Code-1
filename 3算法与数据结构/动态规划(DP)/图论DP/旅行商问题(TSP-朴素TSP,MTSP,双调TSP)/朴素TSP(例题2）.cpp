//HDU 4856
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 16
#define maxq 1005
#define INF  0x3f3f3f//0x7fffff 
using namespace std;
int n,m;
char map[maxn][maxn];
struct node1{
	int x;
	int y;
	int step;
};
node1 now,nex;
node1 queue[maxq];
int used[maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
//以上为BFS用变量 
struct node2{
	int sx;
	int sy;
	int ex;
	int ey;
};
node2 tunn[maxn];
int dis[maxn][maxn]; 
int dp[1<<maxn][maxn];   //注意 
//以上为TSP用变量 
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
void input(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<m;i++){	
		tunn[i].sx=fread()-1;
		tunn[i].sy=fread()-1;
		tunn[i].ex=fread()-1;
		tunn[i].ey=fread()-1;
	}
}

bool judge(int x,int y){
	if(x<0||y<0||x>=n||y>=n) return false;
	if(used[x][y]) return false;
	if(map[x][y]=='#') return false;
	return true;
}
int bfs(int sx,int sy,int ex,int ey){
	int head=0,tail=0;
	memset(queue,0,sizeof(queue));
	memset(used,0,sizeof(used));
	queue[0].x=sx;
	queue[0].y=sy;
	queue[0].step=0;
	used[sx][sy]=1;
	do{
		now=queue[head];
		if(now.x==ex&&now.y==ey) return now.step;
		for(int i=0;i<4;i++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			nex.step=now.step+1;
			if(judge(nex.x,nex.y)){
				used[nex.x][nex.y]=1;
				queue[++tail]=nex;
			}
		}
		head++;
	}while(head<=tail);
	return INF;
}
void cal_dis(){
	memset(dis,INF,sizeof(dis));
	for(int i=0;i<m;i++){
	    for(int j=0;j<m;j++){
	    	if(i==j) dis[i][j]=0;
	    	else{
			   dis[i][j]=min(bfs(tunn[i].ex,tunn[i].ey,tunn[j].sx,tunn[j].sy),dis[i][j]);
			   dis[j][i]=min(bfs(tunn[j].ex,tunn[j].ey,tunn[i].sx,tunn[i].sy),dis[j][i]); 
	    	   //先用bfs算出两个隧道出口和入口之间的距离 
		    }
 	    }
	}
}
int tsp(){//朴素tsp 
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<m;j++){
			dp[i][j]=INF;
		}
	}
//	dp[1][0]=0;
	for(int i=0;i<m;i++) dp[(1<<i)][i]=0; 	
	for(int s=0;s<(1<<m);s++){
		for(int i=0;i<m;i++){
			if((s&(1<<i))==0) continue;
			for(int j=0;j<m;j++){
				if((s&(1<<j))==0||i==j) continue;  //注意括号 
				dp[s][i]=min(dp[s][i],dp[s&~(1<<i)][j]+dis[j][i]);
			}  
		}		
	}
	int ans=INF;
	for(int i=0;i<m;i++){
		ans=min(ans,dp[(1<<m)-1][i]);
	}
	if(ans==INF) return -1;
	else return ans;
	 
}
int main(){
	while(cin>>n>>m){
		input();
		cal_dis();
		//check_dis();
		cout<<tsp()<<endl;
	} 
	return 0;
}
