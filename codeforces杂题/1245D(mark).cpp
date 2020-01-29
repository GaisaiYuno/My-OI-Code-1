#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 2000
using namespace std;
typedef long long ll;
int n; 
struct node{
	int x;
	int y;
	int c;
	int k;
}a[maxn+5];
inline ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
} 

struct edge{
	int from;
	int to;
	ll len;
	int next;
}E[maxn*maxn+5];
int head[maxn+5];
int sz=0;
void add_edge(int u,int v,ll w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
} 
bool cmp(edge p,edge q){
	return p.len<q.len;
}

int fa[maxn+5];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

vector< pair<int,int> >res;
ll kruskal(){
	ll ans=0;
	for(int i=1;i<=n+1;i++) fa[i]=i;
	sort(E+1,E+1+sz,cmp);
	for(int i=1;i<=sz;i++){
		int u=E[i].from,v=E[i].to;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=E[i].len;
			fa[fu]=fv;
			res.push_back(make_pair(E[i].from,E[i].to));
		} 
	}
	return ans;
}

vector<int>poi;//poi~ 
vector< pair<int,int> >edg;
int main(){
	int st;
	scanf("%d",&n);
	st=n+1;
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].c);
		add_edge(st,i,a[i].c);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i].k);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			add_edge(i,j,(a[i].k+a[j].k)*dist(a[i].x,a[i].y,a[j].x,a[j].y));
		}
	}
	printf("%I64d\n",kruskal());
	for(auto ed : res){
		if(ed.first==st) poi.push_back(ed.second);
		else edg.push_back(ed);
	}
	printf("%d\n",poi.size());
	for(int x : poi) printf("%d ",x);
	printf("\n");
	printf("%d\n",edg.size());
	for(auto x : edg) printf("%d %d\n",x.first,x.second); 
}

