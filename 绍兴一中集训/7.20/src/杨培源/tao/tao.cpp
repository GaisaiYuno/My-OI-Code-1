#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 3000
#define maxv 6000
#define maxe 1000000
#define INF 0x3f3f3f3f
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
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

struct edge{
	int from;
	int to;
	int next;
	int flow;
}E[maxe*2+5];
int head[maxv+5];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d vol=%d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
} 

int deep[maxv+5];
bool bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
			}
		}
	}	
	if(deep[t]!=0) return 1;
	else return 0;
}
int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			rest-=k;
			E[i].flow-=k;
			E[i^1].flow+=k;
			if(rest==0) break;
		}
	}
	return minf-rest;
}
int dinic(int s,int t){
	int ans=0;
	int now=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) ans+=now;
	} 
	return ans;
} 


int n,q;
struct node{
	int r;
	int h;
	int id;
}a[maxn+5];

void ini(){
	for(int i=0;i<=n*2+1;i++) head[i]=0;
	sz=1;
}
int solve(int A,int B){
	ini();
	int s=0,t=n*2+1;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(a[i].r>=A&&a[i].h<=B){
			add_edge(s,i,1);
			add_edge(i+n,t,1);
			tot++;
			for(int j=1;j<=n;j++){
				if(a[j].r>=A&&a[j].h<=B){
					if(i!=j&&a[i].r>a[j].r&&a[i].h>a[j].h){
						add_edge(i,j+n,1);
					}
				}
			}
		}
	}
	return tot-dinic(s,t);
}
int main(){
	freopen("tao.in","r",stdin);
	freopen("tao.out","w",stdout);
	int A,B;
	qread(n);
	qread(q); 
	for(int i=1;i<=n;i++){
		qread(a[i].r);
		qread(a[i].h);
	}
	for(int i=1;i<=q;i++){
		qread(A);
		qread(B);
		qprint(solve(A,B));
		putchar('\n');
	}
}
/*
7 3
9 5
3 7
10 6
5 10
2 6
10 10
4 1
10 5
3 5
3 9
*/ 

