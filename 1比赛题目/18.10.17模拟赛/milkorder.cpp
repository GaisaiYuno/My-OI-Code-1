#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define maxn 100005
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

inline void dprint(int x){
	if(x==0) return;
	dprint(x/10);
	putchar(x%10+'0');
}

inline void qprint(int x){
	if(x==0) putchar('0');
	else if(x<0){
		putchar('-');
		dprint(-x);
	}else{
		dprint(x);
	}
	putchar(' ');
}

int n,m;
int a[maxn];
vector<int>G[maxn];

int in[maxn];
struct node{
	int x;
	node(int a){
		x=a;
	}
	friend bool operator <(node a,node b){
		return a.x>b.x;
	}
};
priority_queue<node>q;
vector<int>seq;
void topo_sort(){
	for(int i=1;i<=n;i++){
		int tmp=G[i].size();
		for(int j=0;j<tmp;j++){
			in[G[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(node(i));
	}
	while(!q.empty()){
		int x=q.top().x;
		q.pop();
		seq.push_back(x);
		int tmp=G[x].size();
		for(int i=0;i<tmp;i++){
			int y=G[x][i];
			in[y]--;
			if(in[y]==0) q.push(node(y));
		}
	}
}

int fa[maxn];
void dsu_init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}

int check(int k){
	for(int i=1;i<k;i++){
		int fx=find(a[i]);
		int fy=find(a[i+1]);
		if(fx==fy) return 0;
		else fa[fx]=fy;
	}
	return 1;
}

void add_edge(int k){
	for(int i=1;i<k;i++){
		G[a[i]].push_back(a[i+1]);
	}
}

int main(){
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	int k;
	n=qread();
	m=qread();
	bool ok=false;
	dsu_init();
	for(int i=1;i<=m;i++){
		k=qread();
		for(int j=1;j<=k;j++) a[j]=qread();
		if(ok) continue;
		if(!check(k)) ok=true;
		if(!ok) add_edge(k);
	}
	topo_sort();
	for(int i=0;i<n;i++){
		qprint(seq[i]);
	}
}
