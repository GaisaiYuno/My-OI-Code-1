#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
struct A{
	int x,y,c;
}a[1001];
int m,n,S,T,b[1001][1001],dis[1001][1001],f[1001],q[5001];
int lx[5]={0,0,1,0,-1},ly[5]={0,1,0,-1,0};
bool vis[1001]={0};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(dis,-1,sizeof(dis));
	bool flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		b[a[i].x][a[i].y]=i;
		if(a[i].x==m&&a[i].y==m){
			flag=1;T=i;
		}
		if(a[i].x==1&&a[i].y==1)S=i;
	}
	if(!flag){printf("-1\n");return 0;}
	for(int i=1;i<=n;i++){
		int x=a[i].x,y=a[i].y;
		for(int j=1;j<=4;j++){
			int u=x+lx[j],v=y+ly[j];
			if(u<1||u>m||v<1||v>m)continue;
			int s=b[u][v];
			if(s&&dis[i][s]==-1){
				if(a[s].c==a[i].c)dis[i][s]=0;
				else dis[i][s]=1;
			}else{
				for(int k=1;k<=4;k++){
					int p=u+lx[k],q=v+ly[k];
					if((p==x&&q==y)||p<1||p>m||q<1||q>m)continue;
					int t=b[p][q];
					if(t&&dis[i][t]==-1){
						if(a[t].c==a[i].c)dis[i][t]=2;
						else dis[i][t]=3;
					}
				}
			}
		}
	}
	int h=0,t=1;q[t]=S;
	memset(f,0x7f,sizeof(f));f[S]=0;
	while(h<t){
		h++;
		int u=q[h];
		vis[u]=0;
		for(int v=1;v<=n;v++){
			if(dis[u][v]!=-1&&u!=v){
				if(f[v]>f[u]+dis[u][v]){
					f[v]=f[u]+dis[u][v];
					if(!vis[v]){
						vis[v]=1;
						q[++t]=v;
					}
				}
			}
		}
	}
	if(f[T]>=0x7f)printf("-1\n");
	else printf("%d\n",f[T]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
