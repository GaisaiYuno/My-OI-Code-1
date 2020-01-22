#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

struct edge{int v,l,nxt;}e[80001];

int n,m,x,y,z,ans,cnt,sum,head[10001],dis[10001],f[101][101],map[101][101];
bool in[10001];

void add(int x,int y,int z){e[++cnt].v=y;e[cnt].l=z;e[cnt].nxt=head[x];head[x]=cnt;}

void build(int i,int j){
	if(map[i][j]==map[i-1][j])add(f[i][j],f[i-1][j],0);else if(map[i][j]!=map[i-1][j]&&map[i-1][j])add(f[i][j],f[i-1][j],1);
	if(map[i][j]==map[i][j-1])add(f[i][j],f[i][j-1],0);else if(map[i][j]!=map[i][j-1]&&map[i][j-1])add(f[i][j],f[i][j-1],1);
	if(map[i][j]==map[i+1][j])add(f[i][j],f[i+1][j],0);else if(map[i][j]!=map[i+1][j]&&map[i+1][j])add(f[i][j],f[i+1][j],1);
	if(map[i][j]==map[i][j+1])add(f[i][j],f[i][j+1],0);else if(map[i][j]!=map[i][j+1]&&map[i][j+1])add(f[i][j],f[i][j+1],1);
	if(map[i-1][j-1]){
		int x=map[i][j]==map[i-1][j-1]?0:1;
		if(!map[i][j-1])add(f[i][j],f[i-1][j-1],2+x);else if(!map[i-1][j])add(f[i][j],f[i-1][j-1],2+x);
	}
	if(map[i-1][j+1]){
		int x=map[i][j]==map[i-1][j+1]?0:1;
		if(!map[i][j+1])add(f[i][j],f[i-1][j+1],2+x);else if(!map[i-1][j])add(f[i][j],f[i-1][j+1],2+x);
	}
	if(map[i+1][j-1]){
		int x=map[i][j]==map[i+1][j-1]?0:1;
		if(!map[i][j-1])add(f[i][j],f[i+1][j-1],2+x);else if(!map[i+1][j])add(f[i][j],f[i+1][j-1],2+x);
	}
	if(map[i+1][j+1]){
		int x=map[i][j]==map[i+1][j+1]?0:1;
		if(!map[i][j+1])add(f[i][j],f[i+1][j+1],2+x);else if(!map[i+1][j])add(f[i][j],f[i+1][j+1],2+x);
	}
	if(map[i-2][j]){
		int x=map[i][j]==map[i-2][j]?0:1;
		if(!map[i-1][j])add(f[i][j],f[i-2][j],2+x);
	}
	if(map[i+2][j]){
		int x=map[i][j]==map[i+2][j]?0:1;
		if(!map[i+1][j])add(f[i][j],f[i+2][j],2+x);
	}
	if(map[i][j-2]){
		int x=map[i][j]==map[i][j-2]?0:1;
		if(!map[i][j-1])add(f[i][j],f[i][j-2],2+x);
	}
	if(map[i][j+2]){
		int x=map[i][j]==map[i][j+2]?0:1;
		if(!map[i][j+1])add(f[i][j],f[i][j+2],2+x);
	}
}

int SPFA(int start,int end){
	queue<int>q;
	memset(dis,127,sizeof(dis));
	q.push(start);in[start]=true;dis[start]=0;
	while(!q.empty()){
		int now=q.front();q.pop();in[now]=false;
		for(int i=head[now];~i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[now]+e[i].l){
				dis[v]=dis[now]+e[i].l;
				if(!in[v])q.push(v);
				in[v]=true;
			}
		}
	}
	return dis[end];
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){scanf("%d%d%d",&x,&y,&z);map[x][y]=z+1;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=++sum;	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j])build(i,j);
	ans=SPFA(1,n*n);
	if(ans==0x7f7f7f7f){
		if(dis[f[n-1][n]]!=0x7f7f7f7f)ans=min(ans,dis[f[n-1][n]]+2);
		if(dis[f[n][n-1]]!=0x7f7f7f7f)ans=min(ans,dis[f[n][n-1]]+2);
	}
	printf("%d\n",ans==0x7f7f7f7f?-1:ans);
}
