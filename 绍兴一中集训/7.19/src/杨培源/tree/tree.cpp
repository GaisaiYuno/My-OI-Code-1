#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
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
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

namespace brute_force{
	int dp[maxn+5],maxl[maxn+5];
	void dfs(int x,int fa){
		dp[x]=0;
		maxl[x]=0;
		for(register int i=head[x];i;i=E[i].next){
			register int y=E[i].to;
			if(y!=fa){
				dfs(y,x);
				dp[x]=max(dp[x],dp[y]);
				dp[x]=max(dp[x],maxl[x]+maxl[y]+E[i].len);
				maxl[x]=max(maxl[x],maxl[y]+E[i].len);
			}
		}
	}
	void solve(){
		double ans=0;
		int tot=1<<(n-1);
		for(int i=0;i<tot;i++){
			for(int j=0;j<n-1;j++){
				if(i&(1<<j)){
					E[(j+1)*2].len=2;
					E[(j+1)*2+1].len=2;
				}else{
					E[(j+1)*2].len=1;
					E[(j+1)*2+1].len=1;
				}
			}
			dfs(1,0);
			ans+=1.0/tot*dp[1];
//			printf("%d\n",dp[1]);
		}
		printf("%.10f\n",ans);
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
//	freopen("tree4.in","r",stdin);
	int u,v;
	qread(n);
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	if(n<=25) brute_force::solve();
	return 0;
}


