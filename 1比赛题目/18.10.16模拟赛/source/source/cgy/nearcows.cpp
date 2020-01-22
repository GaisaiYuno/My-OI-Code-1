#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>                    
#include<map>
using namespace std;
#define maxn 100005
void read(int &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	if(f)x=-x;
}
int val[maxn];
struct node{
	int to;
	int next;
}b[maxn<<1];
int head[maxn];
int tot;
void into(int x,int y){
	b[++tot].to=y;
	b[tot].next=head[x];
	head[x]=tot;
}
bool vis[maxn];
int n,k;
long long dp[maxn][25];
long long dp2[maxn][25];
void dfs(int root){
	vis[root]=true;
	dp[root][0]=val[root];
	for(int i=head[root];i;i=b[i].next){
		int y=b[i].to;
		if(vis[y])continue;
		dfs(y);
		for(int j=1;j<=k;j++){
			dp[root][j]+=dp[y][j-1];
		}
	}
}
void dfs2(int root){
	vis[root]=true;
	for(int i=head[root];i;i=b[i].next){
		int y=b[i].to;
		if(vis[y])continue;
		for(int j=2;j<=k;j++){
			dp2[y][j]+=dp[root][j-1]-dp[y][j-2];
			dp2[y][j]+=dp2[root][j-1];
		}
		dp2[y][1]+=dp[root][0];
		dfs2(y);
	}
}
int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	read(n),read(k);
	int x,y;
	for(int i=1;i<n;i++){
		read(x),read(y);
		into(x,y);
		into(y,x);
	}
	for(int i=1;i<=n;i++){
		read(val[i]);
	}
	dfs(1);
	memset(vis,false,sizeof(vis));
	dfs2(1);
	for(int i=1;i<=n;i++){
		long long ans=0;
		for(int j=0;j<=k;j++){
			ans+=dp[i][j]+dp2[i][j];
		}
		printf("%lld\n",ans);
	}
}
