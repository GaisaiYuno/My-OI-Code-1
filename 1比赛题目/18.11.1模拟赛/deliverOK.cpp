//LOJ 6177
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxs 60000
#define maxn 22
#define INF 0x3f3f3f3f
using namespace std;
int n,m,q;
int pow3[maxs];
int dp[maxs][maxn];
int dist[maxn][maxn];
int s[maxn];
int t[maxn];
int l[maxn];
int r[maxn];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
int main(){
	int u,v,w;
	scanf("%d %d %d",&n,&m,&q);
	memset(dist,0x3f,sizeof(dist)); 
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		dist[u][v]=min(dist[u][v],w);
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	floyd();
	for(int i=1;i<=q;i++){
		scanf("%d %d %d %d",&s[i],&t[i],&l[i],&r[i]);
	}
	pow3[0]=1;
	for(int i=1;i<=q;i++){
		pow3[i]=pow3[i-1]*3;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;
	int ans=0,cnt=0;
	for(int i=0;i<pow3[q];i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==INF) continue;
			cnt=0;
			for(int k=1;k<=q;k++){
				int digit=(i/pow3[k-1])%3;
				if(digit==0){
					dp[i+pow3[k-1]][s[k]]=max(min(dp[i+pow3[k-1]][s[k]],dp[i][j]+dist[j][s[k]]),l[k]);
//					 dp[i+pow3[k-1]][s[k]]=min(dp[i+pow3[k-1]][s[k]],max(dp[i][j]+dist[j][s[k]],l[k]));
				}else if(digit==1){
					if(dp[i][j]+dist[j][t[k]]<=r[k]) dp[i+pow3[k-1]][t[k]]=min(dp[i+pow3[k-1]][t[k]],dp[i][j]+dist[j][t[k]]);
				}else cnt++;
			}
			ans=max(ans,cnt); 
		}
	}
	printf("%d\n",ans);
}
