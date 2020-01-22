#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 200000
#define maxm 500000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

int ver[maxm],edge[maxm],Next[maxm],cost[maxm],head[maxn],len=1;
inline void add_edge(int x,int y,int z,int c) {
	ver[++len]=y,edge[len]=z,cost[len]=c,Next[len]=head[x],head[x]=len;
	ver[++len]=x,edge[len]=0,cost[len]=-c,Next[len]=head[y],head[y]=len;
}

int s,t;
int dist[maxn];
bool vis[maxn];
inline void spfa() {
	for (int i=s; i<=t; ++i) dist[i]=-INF;
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(t);
	dist[t]=0,vis[t]=1;
	while (!q.empty()) {
		int x=q.front();
		q.pop();
		vis[x]=0;
		for (int i=head[x]; i; i=Next[i]) {
			int y=ver[i];
			if (edge[i^1] && dist[y]<dist[x]+cost[i^1]) {
				dist[y]=dist[x]+cost[i^1];
				if (!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
}

long long ans;
inline int get(int x,int low) {
	if (x==t) {
		ans+=dist[s]*low;
		return low;
	}
	int tmp=0;
	vis[x]=1;
	for (int i=head[x]; i; i=Next[i]) {
		int y=ver[i];
		if (edge[i] && !vis[y] && dist[x]==dist[y]+cost[i]) {
			int a=get(y,min(low-tmp,edge[i]));
			edge[i]-=a,edge[i^1]+=a,tmp+=a;
			if (tmp==low) return tmp;
		}
	}
	return tmp;
}

inline bool adjust() {
	int tmp=-INF;
	for (int x=s; x<=t; ++x) if (vis[x])
			for (int i=head[x]; i; i=Next[i]) {
				int y=ver[i];
				if (!vis[y] && edge[i]) tmp=max(tmp,dist[y]+cost[i]-dist[x]);
			}
	if (tmp==-INF) return false;
	for (int i=s; i<=t; ++i) if (vis[i]) dist[i]+=tmp;
	return true;
}

inline void zkw() {
	spfa();
	do
		do memset(vis,0,sizeof(vis));
		while (get(s,INF));
	while (adjust());
}



int T,n,A,B;
int a[maxn+5],b[maxn+5];
void ini() {
	len=1;
	memset(head,0,sizeof(head));
	ans=0;
}
int main() {
	freopen("1.in","r",stdin);
	qread(T);
	while(T--) {
		qread(n);
		qread(A);
		qread(B);
		ini();

		s=0,t=n+3;
		int p1=n+1,p2=n+2;
		for(int i=1; i<=n; i++) qread(a[i]);
		for(int i=1; i<=n; i++) qread(b[i]);
		for(int i=1; i<=n; i++) {
			add_edge(s,i,1,0);
			add_edge(i,p1,1,a[i]);
			add_edge(i,p2,1,b[i]);
		}
		add_edge(p1,t,A,0);
		add_edge(p2,t,B,0);
//		printf("ok\n");
		printf("%lld\n",ans);
	}
}
