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
vector<int>a[maxn];
vector<int>G[maxn];
vector<int>E[maxn]; 
int tim=0;
int cnt=0;
bool flag=false;
int dfn[maxn];
int low[maxn];
int ins[maxn];
int sz[maxn];
stack<int>s;
void tarjan_init(){
	tim=0;
	cnt=0;
	flag=false;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(ins,0,sizeof(ins));
	memset(sz,0,sizeof(sz));
	while(!s.empty()) s.top();
} 

void tarjan(int x){
	dfn[x]=low[x]=++tim;
	s.push(x);
	ins[x]=1;
	int tmp=E[x].size();
	for(int i=0;i<tmp;i++){
		int y=E[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		} 
	}
	if(dfn[x]==low[x]){
		cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			sz[cnt]++;
			if(sz[cnt]>1) flag=true;
		}while(x!=y);
	}
}

int check(int k){
	for(int i=1;i<=k;i++){
		for(int j=0;j<a[i].size()-1;j++){
			E[a[i][j]].push_back(a[i][j+1]);
		}
	}
	tarjan_init();
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
		if(flag) return 0;
	}
	for(int i=1;i<=n;i++) E[i].clear();
	return 1;
}

int bin_search(){
	int l=1,r=m;
	int mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
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

int main(){
	int k,u;
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		k=qread();
		for(int j=1;j<=k;j++){
			u=qread();
			a[i].push_back(u);
		}
	}
	int t=bin_search();
	for(int i=1;i<=t;i++){
		for(int j=0;j<a[i].size()-1;j++){
			G[a[i][j]].push_back(a[i][j+1]);
		}
	}
	topo_sort();
	for(int i=0;i<n;i++){
		qprint(seq[i]);
	}
} 
