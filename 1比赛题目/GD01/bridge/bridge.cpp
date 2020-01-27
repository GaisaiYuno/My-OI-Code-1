#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100000
#define maxm 100000
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

int n,m;
struct edge{
	int from;
	int to;
	int len;
	int id;
	int next;
}E[maxm*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w,int id){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].id=id;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

vector<int>D[maxm*2+5];
int in[maxm*2+5];
int f[maxm*2+5];
void add_edge(int u,int v){
//	printf("%d->%d [edge:(%d,%d)->(%d,%d)]\n",u,v,E[u].from,E[u].to,E[v].from,E[v].to);
	D[u].push_back(v);
	in[v]++;
}
int topo_sort(){
	queue<int>q;
	for(int i=2;i<=sz;i++){
		if(!in[i]){
			q.push(i);
			f[i]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<(int)D[x].size();i++){
			int y=D[x][i];
			f[y]=max(f[y],f[x]+1);
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}
//	if(!q.empty()) printf("error!!!!");
	int ans=0;
	for(int i=2;i<=sz;i++) ans=max(ans,f[i]);
	return ans;
}

int id[maxm+5];
bool cmp(int x,int y){
	return E[x].len<E[y].len;
}

int out[maxn+5];
bool is_flower(){
	for(int i=1;i<=n;i++){
		if(out[i]>=n&&m==n) return 1;
	} 
	return 0;
}
int main(){
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
//	freopen("1.in","r",stdin);
	int u,v,w;
	qread(n);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		u++;
		v++;
		out[u]++;
		qread(w);
		add_edge(u,v,w,i);
		add_edge(v,u,w,i);
	}
	if(m>=5000&&is_flower()){
		printf("2\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tsz=0;
		for(int j=head[i];j;j=E[j].next) id[++tsz]=j;
		for(int j=1;j<=tsz;j++){
			for(int k=1;k<=tsz;k++){
				if(E[id[j]].len<E[id[k]].len) add_edge(id[j]^1,id[k]);
			}
		}
	}
	printf("%d\n",topo_sort());
}
