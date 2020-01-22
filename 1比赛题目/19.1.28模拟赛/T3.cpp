/*
For Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005
#define maxk 505
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
int sz=1;
int head[maxn];
inline void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int cnt=0;
int f[maxn][maxk];
int g[maxn][maxk];
void dfs1(int x,int fa){
	f[x][0]=1;
	for(register int i=head[x];i;i=E[i].next){
		register int y=E[i].to;
		if(y!=fa){
			dfs1(y,x);
			for(int j=1;j<=k;j++){
				f[x][j]+=f[y][j-1];
			}
		}
	}
}

void dfs2(int x,int fa){
	for(register int i=head[x];i;i=E[i].next){
		register int y=E[i].to;
		if(y!=fa){
			g[y][0]=1;
			for(int j=1;j<=k;j++){
				g[y][j]=g[x][j-1]-f[y][j-2]+f[y][j];
			}
			
			dfs2(y,x);
		}
	}
}
int main(){
	int u,v;
	qread(n);
	qread(k);
	for(register int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	for(int i=0;i<=k;i++) g[1][i]=f[1][i];
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=g[i][k];
	}
	qprint(ans/2);
}
