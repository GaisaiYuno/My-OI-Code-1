#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<deque>
#include<exception>
#include<fstream>
#include<iostream>
#include<list>
#include<map>
#include<new>
#include<queue>
#include<stack>
#include<vector>
#define FOR(i,s,t) for(int i=(s);i<=(t);i++)
#define REV(i,s,t) for(int i=(s);i>=(t);i--)
#define high(x) x/(int)floor(sqrt(v.u))
#define low(x) x%(int)floor(sqrt(v.u))
#define index(x,y) x*(int)floor(sqrt(v.u))+y
using namespace std;
inline char gc() {
	static char bb[10000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,10000000,stdin),s==t)?EOF:*s++;
}
inline int read() {
	register int x=0;
	register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=gc();
	return x;
}
int n,m,k;
typedef pair<int,int>mp;
priority_queue<mp,vector<mp>,less<mp> >ygy;
int rd[255][255];
int go[255];
int dis[255];
int par[255];
bool mult[255];
int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=n; i++) {
		dis[i]=1000000005;
		for(int u=1; u<=n; u++) {
			rd[i][u]=1000000007;
		}
	}
	for(int i=0; i<m; i++) {
		int x=read(),y=read(),z=read();
		rd[x][y]=rd[y][x]=min(rd[x][y],z);
	}
	ygy.push(mp(0,1));
	while(1) {
		while(ygy.size()&&go[ygy.top().second])ygy.pop();
		if(!ygy.size())break;
		mp a=ygy.top();
		ygy.pop();
		dis[a.second]=a.first;
		for(int i=0; i<n; i++) {
			if(dis[i]==dis[a.second]+rd[i][a.second]) {
				mult[i]=1;
			} else if(dis[i]>dis[a.second]+rd[i][a.second]) {
				dis[i]=dis[a.second]+rd[i][a.second];
				par[i]=a.second;
				mult[i]=0;
				ygy.push(mp(dis[i],i));
			}
		}
	}
	int bd=dis[n];
	int ans=0;
	for(int i=2; i<=n; i++) {
		if(mult[i])continue;
		rd[par[i]][i]=rd[i][par[i]]=2*rd[i][par[i]];
		for(int u=1; u<=n; u++) {
			dis[u]=1000000005;
		}
		memset(go,0,sizeof(go));
		ygy.push(mp(0,1));
		while(1) {
			while(ygy.size()&&go[ygy.top().second])ygy.pop();
			if(!ygy.size())break;
			mp a=ygy.top();
			ygy.pop();
			dis[a.second]=a.first;
			for(int i=0; i<n; i++) {
				if(dis[i]>dis[a.second]+rd[i][a.second]) {
					dis[i]=dis[a.second]+rd[i][a.second];
					ygy.push(mp(dis[i],i));
				}
			}
		}
		ans=max(ans,dis[n]);
		rd[par[i]][i]=rd[i][par[i]]=rd[i][par[i]]/2;
	}
	cout<<ans<<' '<<bd;
}

