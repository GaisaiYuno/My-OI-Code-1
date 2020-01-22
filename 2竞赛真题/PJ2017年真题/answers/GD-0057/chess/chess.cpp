#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 101
using namespace std;
bool vis[MAXN][MAXN],change[MAXN][MAXN],flag;
int m,n,f[MAXN][MAXN],color[MAXN][MAXN];
int go1[5]={0,1,-1,0,0},go2[5]={0,0,0,1,-1};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(color,-1,sizeof(color));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int f,s,z;
		scanf("%d%d%d",&f,&s,&z);
		color[f][s]=z;
	}
	for(int i=1;i<=101;i++){
		for(int j=1;j<=101;j++){
			f[i][j]=99999999;
		}
	}
	f[1][1]=0;
	memset(vis,true,sizeof(vis));
	memset(change,false,sizeof(change));
	queue<int> q1;
	queue<int> q2;
	q1.push(1);q2.push(1);
	while(!q1.empty()&&!q2.empty()){
		int x=q1.front(),y=q2.front();
		q1.pop();q2.pop();
		vis[x][y]=false;
		flag=true;
		for(int i=1;i<=4;i++){
			int tx=x+go1[i],ty=y+go2[i];
			if((color[tx][ty]==0||color[tx][ty]==1)&&vis[tx][ty]&&tx>=1&&tx<=m&&ty>=1&&ty<=m){
				flag=false;
				if(color[tx][ty]==color[x][y]){
					f[tx][ty]=min(f[tx][ty],f[x][y]);
					vis[tx][ty]=false;
					q1.push(tx);q2.push(ty);
					if(change[x][y]){
						change[x][y]=false;
						color[x][y]=2;
					}
				}
				else{
					f[tx][ty]=min(f[tx][ty],f[x][y]+1);
					vis[tx][ty]=false;
					q1.push(tx);q2.push(ty);
					if(change[x][y]){
						change[x][y]=false;
						color[x][y]=2;
					}
				}
			}
		}
		if(!flag)
		for(int i=1;i<=4;i++){
			int tx=x+go1[i],ty=y+go2[i];
			if(color[tx][ty]==-1&&!change[x][y]&&vis[tx][ty]&&tx>=1&&tx<=m&&ty>=1&&ty<=m&&flag){
				int cnt1=0,cnt2=0,ttx,tty;
				for(int j=1;j<=4;j++){
					ttx=tx+go1[j];tty=ty+go2[j];
					if(color[ttx][tty]==1&&vis[ttx][tty]) cnt1++;
					else if(color[ttx][tty]==0&vis[ttx][tty]) cnt2++;
				}
				if(cnt1>cnt2){
					color[tx][ty]=1;
					change[tx][ty]=true;
				}
				else{
					color[tx][ty]=0;
					change[tx][ty]=true;
				}
			}
		}
	}
	if(f[n][n]!=99999999) printf("%d",f[n][n]);
	else printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
