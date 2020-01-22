#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define re register int
using namespace std;
typedef long long ll;
int read() {
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(const int x) {
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int Size=1005;
const int MaxE=100005;
const int INF=0x3f3f3f3f;
struct Edge {
	int v,next;
} w[MaxE<<1];
int n,m,cnt,head[Size],a[MaxE],b[MaxE];
inline void AddEdge(int u,int v) {
	w[++cnt].v=v;
	w[cnt].next=head[u];
	head[u]=cnt;
}
int Queue[Size],d[Size];
bool vis[Size];
int bfs(int s,int t) {
	memset(vis,0,sizeof(vis));
	int hd=0,tl=0;
	Queue[++tl]=s;
	d[s]=0;
	vis[s]=true;
	for(re i=head[s]; i; i=w[i].next) {
		int nxt=w[i].v;
		if(nxt!=t) {
			Queue[++tl]=nxt;
			d[nxt]=1;
			vis[nxt]=true;
		}
	}
	hd++;
	while(hd<tl) {
		int x=Queue[++hd];
		for(re i=head[x]; i; i=w[i].next) {
			int nxt=w[i].v;
			if(!vis[nxt]) {
				if(nxt==t)	return d[x]+1;
				d[nxt]=d[x]+1;
				vis[nxt]=true;
				Queue[++tl]=nxt;
			}
		}
	}
	return -1;
}
int main() {
		freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
//	freopen("T1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();
	m=read();
	for(re i=1; i<=m; i++) {
		a[i]=read();
		b[i]=read();
		AddEdge(a[i],b[i]);
	}
	for(re i=1; i<=m; i++) {
		int ans=bfs(a[i],b[i]);
		if(ans==-1) {
			putchar('-');
			putchar('1');
			putchar(' ');
		} else {
			write(ans);
			putchar(' ');
		}
//		for(re i=1; i<=1e8; i++);
	}
	return 0;
}
