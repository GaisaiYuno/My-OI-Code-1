//HDU 4568
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 205
#define maxk 15
#define INF  2147483647
using namespace std;
int t,n,m,k;
//bfs用变量 
struct node_bfs{
	int x;
	int y;
	int cost;
	//bool operator <(const node_bfs a)const{
	//     return cost<a.cost;
	//}
    friend bool operator < (node_bfs a,node_bfs b){  
    	return a.cost>b.cost;  
    }  
};
priority_queue<node_bfs>q;
node_bfs now,nex;
int map[maxn][maxn];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1}; 
struct node_tre{
	int x;
	int y;
};
node_tre tre[maxk];
int mark[maxn][maxn];//宝藏标记，将有宝藏的点标上编号 
int used[maxn][maxn];//是否走过
int vcount[maxk];//记录每个宝藏访问了几次，应为k次 

//tsp用变量 
int dp[1<<(maxk+1)][maxk];
int dis[maxn][maxn];//dis[0][i]表示从外围到i的距离 
inline int fread(){
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
	memset(map,-1,sizeof(map));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			map[i][j]=fread();
		}
	}
	memset(mark,0,sizeof(mark));
	cin>>k;
	for(int i=1;i<=k;i++){	
        tre[i].x=fread();
		tre[i].y=fread();
		mark[tre[i].x][tre[i].y]=i; 
	}
}
void bfs(int sx,int sy,int i){
	memset(used,0,sizeof(used));
	//printf("i=%d\n",i);
	while(!q.empty()) q.pop();
	now.x=sx;
	now.y=sy;
	now.cost=0;
	q.push(now);
	used[sx][sy]=1;
	while(!q.empty()){ 
		now=q.top();
		q.pop();
		if(dis[i][0]==-1&&(now.x==0||now.y==0||now.x==n||now.y==m)){//到达边缘 
		    //printf("(%d,%d),outdis=%d,indis=%d\n",now.cost,now.cost+map[sx][sy]); 
			dis[i][0]=now.cost;
			dis[0][i]=now.cost+map[sx][sy];
			vcount[i]++;
		}
		else if(mark[now.x][now.y]>0){//到达一个宝藏 
		    //printf("(%d,%d)->(%d,%d),dis=%d\n",sx,sy,now.x,now.y,now.cost); 
			dis[i][mark[now.x][now.y]]=now.cost; 
			vcount[i]++;
		}
		if(vcount[i]>k) return;
		for(int j=0;j<4;j++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			if(used[nex.x][nex.y]==0&&map[nex.x][nex.y]!=-1){
				nex.cost=now.cost+map[nex.x][nex.y];
				used[nex.x][nex.y]=1;
				//printf("(%d,%d) cost=%d",nex.x,nex.y,nex.cost);
				q.push(nex);
			} 
		}
	}
}
void debug(){
    cout<<"dis"<<endl;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
}
int tsp(){ 	
	memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=k;i++) dp[(1<<i)][i]=0; 
    for(int s=0;s<(1<<(k+1));s++){
		for(int i=0;i<=k;i++){
			if((s&(1<<i))==0) continue;
			for(int j=0;j<=k;j++){
				if((s&(1<<j))==0||i==j||dis[j][i]==-1) continue;  //注意括号 
				dp[s][i]=min(dp[s][i],dp[s&~(1<<i)][j]+dis[j][i]);
			}  
		}		
	}
	int ans=INF;
	for(int i=0;i<k;i++){//i枚举终点
	    //printf("%d %d\n",dp[(1<<(k+1))-1][i],dis[i][k]);
	    ans=min(ans,dp[(1<<(k+1))-1][i]+dis[i][k]);	
	}
	if(ans==INF) return 0;
	else return ans;
}
int main(){
    cin>>t;
    while(t--){
     	 input();
     	 memset(dis,-1,sizeof(dis));
		 memset(vcount,0,sizeof(vcount)); 
        for(int i=1;i<=k;i++){
     		bfs(tre[i].x,tre[i].y,i);
     		//dis[i][i]=0;
		}
     	cout<<tsp()<<endl; 
     	//debug();
	}
}
/*
2
3 3
3 2 3
5 4 3
1 4 2
1
1 1
3 3
3 2 3
5 4 3
1 4 2
2
1 1
2 2

8
11
*/ 
