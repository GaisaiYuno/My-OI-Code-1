/*
Problem:CF 161D
Source:http://codeforces.com/problemset/problem/161/D
Description:
点分治
注意：求=k的路径可以用>=k的路径数- >k的路径数 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}
	if(x==0){
		putchar('0');
		return;
	}
	if(x>0){
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
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
int main(){
	int u,v;
	qread(n);
	qread(k);	
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	f[0]=sum=n;
	root=0;
	get_root(1,0);
	solve(root);
	qprint(ans);
}

