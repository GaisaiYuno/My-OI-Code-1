////http://119.29.55.79/contest/86/problem/4
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2500
#define maxans 10000
#define eps 1e-8
#define INF 1e18
using namespace std;
int n,k; 
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int esz=1;
void add_edge(int u,int v){
//	printf("db: %d->%d\n",u,v);
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}

int sz[maxn+5];
int p[maxn+5],s[maxn+5];
double dp[maxn+5][maxn+5];
//void dfs1(int x,int fa){
//	sz[x]=1;
//	for(int i=head[x];i;i=E[i].next){
//		int y=E[i].to;
//		if(y!=fa){
//			dfs1(y,x);
//			sz[x]+=sz[y];
//		}
//	}
//}
void dfs2(int x,int fa,double mid){
	sz[x]=1;
	dp[x][0]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x,mid);
			sz[x]+=sz[y];
			for(int j=min(sz[x],k+1);j>=0;j--){
				for(int t=j;t>=0;t--){
					if(j-t>=0){
						dp[x][j]=max(dp[x][j],dp[x][j-t]+dp[y][t]); 
					}
				}
			}
		}
	}
	for(int j=min(sz[x],k+1);j>0;j--){
		dp[x][j]=dp[x][j-1]+p[x]-mid*s[x];
	}
}

bool check(double mid){
	memset(dp,0xf0,sizeof(dp));
	dfs2(1,0,mid);
	return dp[1][k+1]>=0;
}

int main(){
	int f;
	scanf("%d %d",&k,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&s[i+1],&p[i+1],&f);
		add_edge(f+1,i+1);
		add_edge(i+1,f+1);
	}	
//	dfs1(1,0);
	double l=0,r=maxans;
	double ans=0;
	double mid;
//	check(0.001);
	while(r-l>=eps){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+eps;
		}else r=mid-eps;
	}
	printf("%.3f\n",ans);
} 
