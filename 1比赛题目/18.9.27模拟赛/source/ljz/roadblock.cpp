#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
namespace StandardIO{
	template<typename T>inline void read(T &x){
		x=0;T f=1;char c=getchar();
		for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
		x*=f;
	}
	template<typename T>inline void write(T x){
		if(x<0)putchar('-'),x*=-1;
		if(x>=10)write(x/10);
		putchar(x%10+'0');
	}
}
using namespace StandardIO;
namespace Solve{
	const int N=250250;
	const int INF=2147483647;
	int n,m,ans;
	int cnt;
	int head[N];
	struct node{
		int to,next,val;
	}edge[N<<1];
	template<typename T>inline void add(T a,T b,T c){
		edge[++cnt].to=b,edge[cnt].val=c,edge[cnt].next=head[a],head[a]=cnt;
	}
	struct qnode{
		int key,val;
		bool operator < (const qnode x)const{
			return val>x.val;
		}
	};
	int dis[N],vis[N];
	template<typename T>inline T dijkstra(T s){
		for(register T i=1;i<=n;++i)dis[i]=INF,vis[i]=false;
		dis[s]=0;priority_queue<qnode>q;q.push((qnode){s,0});
		while(!q.empty()){
			qnode tmp=q.top();q.pop();
			if(vis[tmp.key])continue;
			vis[tmp.key]=1;
			for(register T i=head[tmp.key];i;i=edge[i].next){
				T to=edge[i].to;
				if(!vis[to]&&dis[to]>tmp.val+edge[i].val){
					dis[to]=tmp.val+edge[i].val;
					q.push((qnode){to,dis[to]});
				}
			}
		}
		return dis[n];
	}
	inline void solve(){
		read(n),read(m);
		for(register int i=1;i<=m;++i){
			int a,b,c;
			read(a),read(b),read(c);
			add(a,b,c),add(b,a,c);
		}
		for(register int i=1;i<=2*m-1;i+=2){
			edge[i].val*=2,edge[i+1].val*=2;
			ans=max(ans,dijkstra(1));
			edge[i].val/=2,edge[i+1].val/=2;
		}
		write(ans-dijkstra(1));
	}
}
using namespace Solve;
int main(){
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	solve();
}
