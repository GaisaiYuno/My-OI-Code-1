#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,x,y,c,u,v,cnt,ans,a[105][105],head[20005],to[200005],nxt[200005],dd[200005];
void adde(int u,int v,int d){
	to[++cnt]=v;
	dd[cnt]=d;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void link(int xl,int yl,int xr,int yr){
	if(xr<1||xr>n||yr<1||yr>n){
		return;
	}
	if(a[xl][yl]){
		if(a[xl][yl]==a[xr][yr]){
			adde((xl-1)*n+yl,(xr-1)*n+yr,0);
		}else if(a[xr][yr]){
			adde((xl-1)*n+yl,(xr-1)*n+yr,1);
		}else{
			if(a[xl][yl]==1){
				adde((xl-1)*n+yl,(xr-1)*n+yr,2);
				adde((xl-1)*n+yl,(xr-1)*n+yr+n*n,3);
			}
			else{
				adde((xl-1)*n+yl,(xr-1)*n+yr,3);
				adde((xl-1)*n+yl,(xr-1)*n+yr+n*n,2);
			}
		}
	}else{
		if(a[xr][yr]==1){
			adde((xl-1)*n+yl,(xr-1)*n+yr,0);
			adde((xl-1)*n+yl+n*n,(xr-1)*n+yr,1);
		}else if(a[xr][yr]==2){
			adde((xl-1)*n+yl,(xr-1)*n+yr,1);
			adde((xl-1)*n+yl+n*n,(xr-1)*n+yr,0);
		}
	}
}
struct data{
	int v,d;
	data(){}
	data(int v,int d):v(v),d(d){}
	bool operator < (const data b) const{
		return d>b.d;
	}
}now;
priority_queue<data> q;
int dis[20005];
bool vis[20005];
void dij(int s){
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	q.push(data(s,0));
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(vis[now.v]){
			continue;
		}
		vis[now.v]=true;
		for(int i=head[now.v];i;i=nxt[i]){
			if(!vis[to[i]]&&dis[now.v]+dd[i]<dis[to[i]]){
				dis[to[i]]=dis[now.v]+dd[i];
				q.push(data(to[i],dis[to[i]]));
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			link(i,j,i-1,j);
			link(i,j,i+1,j);
			link(i,j,i,j-1);
			link(i,j,i,j+1);
		}
	}
	dij(1);
	if(a[n][n]){
		ans=dis[n*n];
	}else{
		ans=min(dis[n*n],dis[2*n*n]);
	}
	printf("%d\n",ans==dis[0]?-1:ans);
	return 0;
}
