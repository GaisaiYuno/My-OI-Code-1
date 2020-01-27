//用id数组记录比直接swap要节省内存，但直接swap并不影响时间
//此题在洛谷上不用id数组会MLE 
#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 200000
using namespace std;
typedef long long ll;
int n;
ll a[maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int id[maxn+5];
priority_queue<ll>s[maxn+5];
vector<ll>tmp;
void merge(int x,int y){
	if(s[id[x]].size()<s[id[y]].size()) swap(id[x],id[y]);
	while(!s[id[y]].empty()){
		tmp.push_back(max(s[id[x]].top(),s[id[y]].top()));
		s[id[x]].pop();
		s[id[y]].pop();
	}
	for(int i=0;i<(int)tmp.size();i++) s[id[x]].push(tmp[i]);
	tmp.clear();
} 
int tim=0;
void dfs(int x,int fa){
	id[x]=++tim;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			merge(x,y);
		} 
	}
	s[id[x]].push(a[x]);
}

int main(){
	int ff;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++){
		scanf("%d",&ff);
		add_edge(ff,i);
		add_edge(i,ff);
	}
	dfs(1,0);
	ll ans=0;
	while(!s[id[1]].empty()){
		ans+=s[id[1]].top();
		s[id[1]].pop();
	}
	printf("%lld\n",ans);
}
