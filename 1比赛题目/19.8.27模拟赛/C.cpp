#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define maxn 200000
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
int n;
int a[maxn+5]; 
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
multiset<int>s[maxn+5];
void merge(int x,int y){
	if(s[x].size()<s[y].size()) swap(s[x],s[y]);
	for(multiset<int>::iterator it=s[y].begin();it!=s[y].end();it++){
		s[x].insert(*it);
	}
	s[y].clear();
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			merge(x,y);
		}
	}
	multiset<int>::iterator it=s[x].upper_bound(a[x]);
	if(it!=s[x].end()) s[x].erase(it);
	s[x].insert(a[x]);
}

int main(){
//	freopen("3.in","r",stdin);
	int u,v;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i]);
//		a[i]-=i;
		a[i]=-a[i];
	}
//#ifdef DEBUG
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	printf("\n");
//#endif
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	printf("%d\n",n-s[1].size());
}
