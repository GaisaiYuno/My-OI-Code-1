#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#define maxn 200005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
struct edge {
	int from;
	int to;
	edge() {

	}
	edge(int u,int v) {
		from=u;
		to=v;
	}
	friend bool operator <(edge a,edge b) {
		if(a.from==b.from) return a.to<b.to;
		else return a.from<b.from;
	}
};
set<edge>S;
int n;
int cnt[maxn];
long long sum[maxn];
vector<int>E[maxn];
int test=0;
void add_edge(int u,int v) {
	if(S.count(edge(u,v))||S.count(edge(v,u))) return;
	if(u==v+1||v==u+1) return;
	test++;
	cnt[u]++;
	cnt[v]++;
	S.insert(edge(u,v));
	S.insert(edge(v,u));
	E[u].push_back(v);
	E[v].push_back(u);
}

int count_edge(int u,int l,int r){//u中属于(l,r)的边的个数 
	int t1=upper_bound(E[u].begin(),E[u].end(),l)-E[u].begin();
	int t2=lower_bound(E[u].begin(),E[u].end(),r)-E[u].begin()-1;
	return t2-t1+1;
}
int count(int x,int y) {
	if(S.count(edge(x,y))) return -1;
	if(x>y) swap(x,y);
	int ans=sum[y-1]-sum[x];
	int t1=count_edge(x,x,y);
	int t2=count_edge(y,x,y);
	return ans-t1-t2; 
}

int main() {
	freopen("triangulation.in","r",stdin);
	freopen("triangulation.out","w",stdout);
	int p,q,r;
	n=qread();
	for(int i=1; i<=n-2; i++) {
//		scanf("%d %d %d",&p,&q,&r);
		p=qread();
		q=qread();
		r=qread();
		add_edge(p,q);
		add_edge(p,r);
		add_edge(r,q);
	}
//	printf("%d\n",test);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	int ans=0;
//	printf("debug:%d\n",count(2,n));
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			ans=max(ans,count(i,j)+1);
		}
	}
	printf("%d\n",ans);
}
