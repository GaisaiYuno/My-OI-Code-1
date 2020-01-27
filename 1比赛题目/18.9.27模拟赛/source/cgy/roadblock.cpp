#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
#define maxn 255
int n,m;
int mp[maxn][maxn];
long long mi[maxn][maxn];
int ed[maxn][maxn];
bool vs[maxn][maxn];
long long dis[maxn];
bool vis[maxn];
bool ct[maxn][maxn];
long long ans;
void dij(int t1,int t2){
	priority_queue< pair<int,int> > q;
	memset(dis,0x3F,sizeof(dis));
	memset(vis,false,sizeof(vis));
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(int i=1;i<=ed[x][0];i++){
			int y=ed[x][i];
			long long z=mi[x][y];
			if(x==0 || y==0)continue;
			//cout<<x<<" "<<y<<endl;
			if((x==t1 && y==t2) || (y==t1 && x==t2)){
				z*=2;
		//		cout<<x<<" "<<y<<endl;
		//		cout<<t1<<" "<<t2<<endl;
			}
			if(dis[x]+z<dis[y]){
		//		cout<<x<<" "<<y<<endl;
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
int main(){
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y;
    long long z;
    memset(mi,0x3F,sizeof(mi));
//    cout<<m<<endl;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%lld",&x,&y,&z);
    	if(z>=mi[x][y]){
    		continue;
		}
		else{
			if(!mp[x][y]){
				ed[x][++ed[x][0]]=y;
				ed[y][++ed[y][0]]=x;
				mp[x][y]=ed[x][0];
				mp[y][x]=ed[y][0];
				mi[x][y]=mi[y][x]=min(mi[x][y],z);
			}
			else{
				ed[x][mp[x][y]]=y;
				ed[y][mp[y][x]]=x;
				mi[x][y]=mi[y][x]=min(mi[x][y],z);				
			}
		}
	}
	dij(0,0);
	long long mi=dis[n];
	long long mx=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=ed[i][0];j++){
//    		cout<<i<<" "<<j<<endl;
    		if(ct[i][ed[i][j]] || ct[ed[i][j]][i])continue;
//    		cout<<i<<" "<<ed[i][j]<<endl;
    		ct[i][ed[i][j]]=true;
//    		cout<<mi[i][ed[i][j]]<<endl;
    		dij(i,ed[i][j]);
    		mx=max(mx,dis[n]);
    		//cout<<dis[n]<<endl;
		}
	}
	cout<<mx-mi<<endl;
}
