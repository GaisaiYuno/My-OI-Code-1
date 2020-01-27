#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define maxm 100
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
//	printf("%d %d\n",u,v);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int main(){
	freopen("quadripartite.in","r",stdin);
	freopen("quadripartite.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,j+n);
			add_edge(i,n+i-j+n*2);
			add_edge(j+n,i+j-1+n*3);
			add_edge(n+i-j+n*2,i+j-1+n*3);
		}
	}
	printf("%d\n%d\n",n,n*2);
//	printf("%d\n",sz);
}
