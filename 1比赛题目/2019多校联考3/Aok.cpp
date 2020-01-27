#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 1000
#define maxm 100000
using namespace std;
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

inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar(x%10+'0');
	}
}
int n,m;
vector<int>E[maxn+5];

bool vis[maxn+5];
int deep[maxn+5];
int q[maxn+5];
int hd,tl;
int bfs(int s,int t) {
	memset(vis,0,sizeof(vis));
	hd=1,tl=0;
	q[++tl]=s;
	deep[s]=0;
	vis[s]=1;
	while(hd<=tl) {
		int x=q[hd];
		hd++;
		for(int i=0;i<E[x].size();i++) {
			int y=E[x][i];
			if(x==s&&y==t) continue;
			if(!vis[y]) {
				q[++tl]=y;
				vis[y]=1;
				deep[y]=deep[x]+1;
				if(y==t) return deep[y];	
			}
		}
	}
	return -1;
}

int s[maxm+5],t[maxm+5];
int main() {
//	freopen("1.in","r",stdin);
//	freopen("1.ans","w",stdout);
	int u,v;
	qread(n);
	qread(m);
	for(int i=1; i<=m; i++) {
		qread(u);
		qread(v);
		E[u].push_back(v);
		s[i]=u;
		t[i]=v;
	}
	for(int i=1; i<=m; i++) {
		qprint(bfs(s[i],t[i]));
		putchar(' ');
	}

}

