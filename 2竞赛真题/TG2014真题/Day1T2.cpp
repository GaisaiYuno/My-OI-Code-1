#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 10007
#define maxn 200005
using namespace std;
int n;
long long w[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int sz=0;
int head[maxn];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

long long ans=0;
long long sum=0;
void dfs(int x,int fa,int gf){
	long long top1=0,top2=0; 
	long long tot=0;
	long long stot=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			tot+=w[y];
			tot%=mod;
			stot+=w[y]*w[y]%mod;
			stot%=mod;
			if(w[y]>top1){
				top2=top1;
				top1=w[y]; 
			}else if(w[y]>top2){
				top2=w[y];
			} 
			dfs(y,x,fa);
		} 
	}
	ans=max(ans,max(top1*top2,w[x]*w[gf]));
	sum+=((tot*tot%mod-stot+mod)%mod);
	sum+=w[x]*w[gf]*2%mod;
	sum%=mod;
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	dfs(1,0,0);
	printf("%lld %lld\n",ans,sum);
}
