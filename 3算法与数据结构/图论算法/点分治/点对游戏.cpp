/*
Problem:╣Ц╤тсно╥
Source:http://119.29.55.79/contest/28/problem/5
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005 
using namespace std;


int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int ecnt=1;
int head[maxn];
inline void add_edge(int u,int v){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int root=0,sum;
int f[maxn];
int sz[maxn];
int vis[maxn];
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
	f[x]=max(f[x],sum-f[x]);
	if(f[x]<f[root]) root=x; 
}

int cnt=0;
int deep[maxn];
int res[maxn];
void get_deep(int x,int fa){
	res[++cnt]=deep[x];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			deep[y]=deep[x]+1;
			get_deep(y,x);
		}
	}
}

int calc(int x,int d0){
	deep[x]=d0;
	cnt=0;
	get_deep(x,0);
	sort(res+1,res+1+cnt);
	int l=1,r=cnt;
	int ans1=0;
	while(l<r){
		if(res[l]+res[r]<=k){
			ans1+=(r-l);
			l++;
		}else r--;
	}
	
	l=1,r=cnt;
	int ans2=0;
	while(l<r){
		if(res[l]+res[r]<k){
			ans2+=(r-l);
			l++;
		}else r--;
	}
	return ans1-ans2;
}

int ans=0;
void solve(int x){
	vis[x]=1;
	ans+=calc(x,0);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			ans-=calc(y,1);
			root=0;
			sum=sz[y];
			get_root(y,0);
			solve(root);
		}
	}
}

void divide_ini(){
	memset(deep,0,sizeof(deep));
	memset(f,0,sizeof(f));
	memset(sz,0,sizeof(sz));
	memset(vis,0,sizeof(vis));
	root=0;
	sum=n;
	f[0]=n;
	get_root(1,0);
}

int m;
int num[maxn];
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=m;i++){
		k=num[i];
		divide_ini();
		solve(root); 
	}
	double k1,k2,k3;
	if(n%3==0) k1=k2=k3=n/3;
	else if(n%3==1){
		k1=n/3+1;
		k2=n/3;
		k3=n/3;
	}else{
		k1=n/3+1;
		k2=n/3+1;
		k3=n/3;
	}
	printf("%.2lf\n",ans*k1*(k1-1)/((double)n*(n-1)));
	printf("%.2lf\n",ans*k2*(k2-1)/((double)n*(n-1)));
	printf("%.2lf\n",ans*k3*(k3-1)/((double)n*(n-1)));
}
