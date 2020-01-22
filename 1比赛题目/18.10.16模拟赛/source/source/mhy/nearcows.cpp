#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 100005
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		ch=getchar();
	}
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a;}
vector<int>G[MAXN];
struct node{
	int u,len;
};
int vis[MAXN],n,ans[MAXN];
node Q[MAXN];
inline void bfs(int s,int k,int val){
	int front=0,rear=0;
	node temp;
	temp.u=s,temp.len=0;
	Q[++rear]=temp;
	while (front<=rear){
		node fa=Q[front++];
		if (fa.len==k) continue;
		node ch;
		for (register int i=0;i<G[fa.u].size();++i){
			if (!vis[G[fa.u][i]]){
				vis[G[fa.u][i]]=true;
				ch.u=G[fa.u][i],ch.len=fa.len+1;
				Q[++rear]=ch;
			}
		}
	}
	for (register int i=1;i<=n;++i){
		if (vis[i]) ans[i]+=val,vis[i]=0;
	}
}
void print(int x){
	if (x>9) print(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	int k;
	scanf("%d%d",&n,&k);
	for (register int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	for (register int i=1;i<=n;++i) bfs(i,k,read());
	for (register int i=1;i<=n;++i){
		print(ans[i]),putchar('\n');
	}
}
