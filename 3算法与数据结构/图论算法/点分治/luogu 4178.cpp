/*
Problem:Tree 
Source:https://www.luogu.org/problemnew/show/P4178
Description:
点分治模板
https://www.cnblogs.com/zhoushuyu/p/8137645.html 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40005
using namespace std;
int n,k; 
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int ecnt=1;
int head[maxn];
void add_edge(int u,int v,int w){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	E[ecnt].len=w;
	head[u]=ecnt;
}

int root;//重心 
int sum;//当前分治的子树大小 
int sz[maxn];
int f[maxn];//去掉x点后的子树的最大值 
int vis[maxn];//是否被选做重心 
void get_root(int x,int fa){
	sz[x]=1;
	f[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			sz[x]+=sz[y];
			f[x]=max(f[x],sz[y]);
		}
	}
	f[x]=max(f[x],sum-sz[x]);
	if(f[x]<f[root]) root=x; 
}

int cnt=0;
int deep[maxn];
int res[maxn];//存储结果，方便计算答案 
void get_deep(int x,int fa){
	res[++cnt]=deep[x];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			deep[y]=deep[x]+E[i].len;
			get_deep(y,x);	
		}
	}
}

int calc(int x,int d0){
	cnt=0;
	deep[x]=d0;
	get_deep(x,0);
	sort(res+1,res+1+cnt);
	int l=1,r=cnt,ans=0;
	while(l<r){
		if(res[l]+res[r]<=k){
			ans+=r-l;
			l++;
		}else r--;
	}
	return ans; 
}

int ans=0;
void solve(int x){
	ans+=calc(x,0);
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			ans-=calc(y,E[i].len);
			sum=sz[y];
			root=0;
			get_root(y,0);
			solve(root);//记得一定是solve(root),不是solve(y) 
		}
	} 
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	scanf("%d",&k);
	root=0;
	sum=f[0]=n;//f[0]=n,相当于先把f[root]设为INF，这样就可以计算出最大的子树最小的值 
	get_root(1,0);//记得先处理一个根 
	solve(root);//不是solve(1) 
	printf("%d\n",ans);
}
