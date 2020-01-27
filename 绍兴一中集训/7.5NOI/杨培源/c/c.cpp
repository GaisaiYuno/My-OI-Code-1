#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5000
#define maxm 12497500
using namespace std;
int n,m;
char s[maxn+5];
int a[maxn+5];
int to_int(char *s){
	int len=strlen(s);
	int x=0;
	for(int i=0;i<len;i++){
		x=x*2+(s[i]=='L');
	}
	return x;
}

int count_1(int x){
	int ans=0;
	while(x>0){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

struct edge{
	int from;
	int to;
	int next;
	int len;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;
	}
}E[maxm+5];
int sz=0;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

int fa[maxn+5];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

int kruskal(){
	int ans=0;
	for(int i=1;i<=m;i++) fa[i]=i;
	sort(E+1,E+1+sz);
	for(int i=1;i<=sz;i++){
		int x=E[i].from,y=E[i].to,fx=find(x),fy=find(y);
		if(fx!=fy){
			ans+=E[i].len;
			fa[fx]=fy;
		}
	}
	return ans;
}
int main(){
#ifndef LOCAL
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		a[i]=to_int(s); 
	} 

	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			add_edge(i,j,count_1(a[i]^a[j]));
		}
	}
	printf("%d\n",kruskal());
}
