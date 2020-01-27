#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#define maxn 10005
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

int n,m,k;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn<<1];
int head[maxn];
int in[maxn];
int sz=0;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

queue<int>q;
vector<long long>s[maxn];
vector<long long>tmp;
void merge(int from,int to,int len){
	int i=0,j=0;
	int n=s[from].size();
	int m=s[to].size();
	tmp.clear();
	while(i<n&&j<m){
		if(s[from][i]+len<s[to][j]){
			tmp.push_back(s[from][i++]+len);
		}else{
			tmp.push_back(s[to][j++]);
		}
	}
	if(i<n){
		while(i<n) tmp.push_back(s[from][i++]+len);
	}
	if(j<m){
		while(j<m) tmp.push_back(s[to][j++]);
	}
	int newsz=min((int)tmp.size(),100);
	s[to].resize(newsz);
	for(int i=0;i<newsz;i++) s[to][i]=tmp[i];
}
void topo_sort(){
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	s[n].push_back(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			merge(x,y,E[i].len);
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}
}
int main(){
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
	int u,v,w;
	n=qread();
	m=qread();
	k=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		w=qread();
		add_edge(u,v,w);
		in[v]++;
	}
	topo_sort();
//	printf("debug%d\n",dp[1]);
	int t=s[1].size();
	if(t>=k){
		for(int i=0;i<k;i++){
			printf("%lld\n",s[1][i]);
		}
	}else{
		for(int i=0;i<t;i++){
			printf("%lld\n",s[1][i]);
		}
		for(int i=1;i<=k-t;i++){
			printf("-1\n");
		}
	}
	return 0;
}
