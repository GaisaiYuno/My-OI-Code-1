#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define inf 1<<30
ll read()
{
	ll tmp=0; char c=getchar(),f=1;
	while(c<'0'||'9'<c){if(c=='-')f=-1; c=getchar();}
	while('0'<=c&&c<='9'){tmp=tmp*10+c-'0'; c=getchar();}
	return tmp*f;
}
using namespace std;
int fir[1010]={0},ne[1000010],to[1000010],w[1000010];
int vis[1010],dist[1010];
int q[3000010];
int x[1010],y[1010],col[1010];
int n,m,tot=0;
void add(int x,int y,int z){to[++tot]=y; w[tot]=z; ne[tot]=fir[x]; fir[x]=tot;}
int find(int xx,int yy)
{
	for(int i=1;i<=n;i++)if(x[i]==xx&&y[i]==yy)return i;
	return 0;
}
void spfa(int s)
{
	int i;
	for(i=1;i<=n;i++)dist[i]=inf,vis[i]=0;
	int h=1,t=1; q[1]=s; dist[s]=0; vis[s]=1;
	while(h<=t){
		for(i=fir[q[h]];i;i=ne[i])
			if(dist[to[i]]>dist[q[h]]+w[i]){
				dist[to[i]]=dist[q[h]]+w[i];
				if(!vis[to[i]]){
					q[++t]=to[i]; vis[to[i]]=1;
				}
			}
		vis[q[h++]]=0;
	}
	//for(i=1;i<=n;i++)printf("%d ",dist[i]); printf("\n");
}
int main()
{
	int i,j;
	freopen("chess.in","r",stdin); freopen("chess.out","w",stdout);
	m=read(); n=read();
	for(i=1;i<=n;i++)x[i]=read(),y[i]=read(),col[i]=read();
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			int dist=abs(x[i]-x[j])+abs(y[i]-y[j]);
			if(dist==1){
				if(col[i]==col[j])add(i,j,0);else add(i,j,1);
			}
			else if(dist==2){
				if(col[i]==col[j])add(i,j,2);else add(i,j,3);
			}
		}
	spfa(find(1,1));
	int ans=inf;
	if(find(m,m))ans=dist[find(m,m)];
	else{
		if(find(m,m-1))ans=min(ans,dist[find(m,m-1)]+2);
		if(find(m-1,m))ans=min(ans,dist[find(m-1,m)]+2);
	}
	if(ans<inf)printf("%d\n",ans);else printf("-1\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
