#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000
#define maxm 10000
#define INF 0x3f3f3f3f
using namespace std;
int n,t;
const int tim=24;
int r[maxn+5],peo[maxn+5];
struct edge {
	int from;
	int to;
	int next;
	int len;
} E[maxm*2+5];
int head[maxn+5];
int sz;
void add_edge(int u,int v,int w) {
//	printf("%d->%d len=%d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

queue<int>q;
int cnt[maxn+5],dist[maxn+5];
bool inq[maxn+5];
bool spfa(int s) {
	while(!q.empty()) q.pop();
	for(int i=0; i<=tim*2; i++) {
		dist[i]=-INF;
		cnt[i]=0;
		inq[i]=0;
	}
	q.push(s);
	dist[s]=0;
	inq[s]=1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(dist[y]<dist[x]+E[i].len) {//spfa求最长路 
				dist[y]=dist[x]+E[i].len;
				if(!inq[y]) {
					cnt[y]++;
					if(cnt[y]>tim*2) return 0;
					q.push(y);
					inq[y]=1;
				}
			}

		}
	}
	return 1;
}

bool check(int mid) {
	sz=1;
	for(int i=0; i<=tim*2; i++) head[i]=0;
	for(int i=1; i<=tim*2; i++) {
		if(i>=8) {
			//d[i]-d[i-8]>=r[i]
			add_edge(i-8,i,r[i]);
		}
		if(i>=24) {
			//实际上是d[i]-d[i-24]=mid,拆成不等式的形式
			//d[i]-d[i-24]>=mid
			add_edge(i-24,i,mid);
			//d[i]-d[i-24]<=mid
			add_edge(i,i-24,-mid);
		}
		//d[i]-d[i-1]>=0
		add_edge(i-1,i,0);
		//d[i]-d[i-1]<=peo[i]
		add_edge(i,i-1,-peo[i]);
	}
	return spfa(0);
}

void ini() {
	sz=1;
	for(int i=1; i<=tim*2; i++) head[i]=0;
	for(int i=1; i<=tim*2; i++) peo[i]=0;
}
int main() {
	int x;
	scanf("%d",&t);
	while(t--) {
		for(int i=1; i<=tim; i++) {
			scanf("%d",&r[i]);
		}
		scanf("%d",&n);
		ini();
		for(int i=1; i<=n; i++) {
			scanf("%d",&x);
			peo[x+1]++;//默认时间从1开始 
		}
		for(int i=1;i<=tim;i++){//断环为链 
			r[i+tim]=r[i];
			peo[i+tim]=peo[i];
		} 
		int l=0,r=n,mid,ans=n+1;
		while(l<=r) {
			mid=(l+r)>>1;
			if(check(mid)) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(ans==n+1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
}

