//Dedicated to Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define maxn 200005
using namespace std;
int n;
int a[maxn];
struct edge{
	int from;
	int to;
	int next; 
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
set<int>s[maxn];
void dfs(int x,int fa,int v){
	s[x].insert(v);//不选a[x]
	set<int>::iterator it;
	int pv;
	for(it=s[fa].begin();it!=s[fa].end();it++){//选a[x]和父节点所有符合条件的值 
		pv=*it;
		s[x].insert(gcd(a[x],pv)); 
	}
	v=gcd(v,a[x]);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to; 
		if(y!=fa){
			dfs(y,x,v);	
		}
	} 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	s[1].insert(a[1]);
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		printf("%d ", *s[i].rbegin());
	} 
}
